/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:53:18 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 16:32:58 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define ASM_DEF_HEADER	{COREWAR_EXEC_MAGIC,{0},0,{0}}
#define ASM_PARSE_RET(...)	return (ret < 0 ? -1 : parse_error(__VA_ARGS__))

static inline int		parse_header(int fd, t_header *header)
{
	FT_INIT(int, ret, 0);
	FT_INIT(t_token, *t[4], FT_BRACKETS(NULL));
	if (((ret = lexer(fd, t)) <= 0) || ((t[0]->type != TOK_TYPE_NAME)
			&& (t[0]->type != TOK_TYPE_COM)))
		ASM_PARSE_RET(t[0], 2, TOK_TYPE_NAME, TOK_TYPE_COM);
	if (((ret = lexer(fd, t + 1)) <= 0) || (t[1]->type != TOK_TYPE_STRING))
		ASM_PARSE_RET(t[1], 1, TOK_TYPE_STRING);
	if (((ret = lexer(fd, t + 2)) <= 0) ||
			((t[0]->type == TOK_TYPE_NAME) && (t[2]->type != TOK_TYPE_COM)) ||
			((t[0]->type == TOK_TYPE_COM) && (t[2]->type != TOK_TYPE_NAME)))
		ASM_PARSE_RET(t[2], 1,
				(t[0]->type == TOK_TYPE_NAME ? TOK_TYPE_COM : TOK_TYPE_NAME));
	if (((ret = lexer(fd, t + 3)) <= 0) || (t[3]->type != TOK_TYPE_STRING))
		ASM_PARSE_RET(t[3], 1, TOK_TYPE_STRING);
	if (t[0]->type == TOK_TYPE_NAME)
	{
		ft_strncpy(header->prog_name, t[1]->tok + 1, ft_strlen(t[1]->tok) - 2);
		ft_strncpy(header->comment, t[3]->tok + 1, ft_strlen(t[3]->tok) - 2);
	}
	else
	{
		ft_strncpy(header->prog_name, t[3]->tok + 1, ft_strlen(t[3]->tok) - 2);
		ft_strncpy(header->comment, t[1]->tok + 1, ft_strlen(t[1]->tok) - 2);
	}
	return (0);
}

static inline int		parser_ftn(int fd, t_parser_file *file, t_token *t)
{
	FT_INIT(t_op const, *cur_op, g_op_tab + t->type);
	FT_INIT(unsigned char, byte_code, '\0');
	file->data[file->index++] = (char)cur_op->opcode;
	if (FT_FOR(FT_INIT(size_t, i, 0), i < cur_op->nparams, ++i))
	{
		if (lexer(fd, &t))
			return (-1);
		if ((cur_op->params[i] & T_REG) && (t->type == TOK_TYPE_REG))
			; //register
		else if ((cur_op->params[i] & T_DIR) && ((t->type ==
					TOK_TYPE_DIR_LBL) || (t->type == TOK_TYPE_DIR_NBR)))
			; //direct
		else if ((cur_op->params[i] & T_IND) && ((t->type ==
					TOK_TYPE_IND_LBL) || (t->type == TOK_TYPE_IND_NBR)))
			; //indirect
		else
			return (parse_error(t, 0)); //TODO add required type
		if (i < cur_op->nparams)
			if (lexer(fd, &t))
				return (-1);
			else if (t->type != TOK_TYPE_SEP)
				return (parse_error(t, 1, TOK_TYPE_SEP));
	}
	return (0);
}

int						parser(int fd, t_parser_file *file)
{
	FT_INIT(t_header, header, ASM_DEF_HEADER);
	FT_INIT(t_token, *t, NULL);
	if (parse_header(fd, &header))
		return (-1);
	while (lexer(fd, &t))
	{
		//checker l'index de 'file'
		if (t->type == TOK_TYPE_LBL)
			;//gerer label
		else if ((t->type >= TOK_TYPE_LIVE) && (t->type <= TOK_TYPE_AFF))
			parser_ftn(fd, file, t);
		else
			return (parse_error(t, 16, TOK_TYPE_LIVE, TOK_TYPE_LD, TOK_TYPE_ST,
						TOK_TYPE_ADD, TOK_TYPE_SUB, TOK_TYPE_AND, TOK_TYPE_OR,
						TOK_TYPE_XOR, TOK_TYPE_ZJMP, TOK_TYPE_LDI, TOK_TYPE_STI,
						TOK_TYPE_FORK, TOK_TYPE_LLD, TOK_TYPE_LLDI,
						TOK_TYPE_LFORK, TOK_TYPE_AFF));
	}
	return (0);
}
