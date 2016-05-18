/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:28:59 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/01/28 11:19:15 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define NULLARRAY		{{0}, {0}}

#define TOK_DELIM		SEPARATOR_CHAR BLANK_CHARS

static inline int		lexer_error(char *str, t_token *tok)
{
	ft_dprintf(2, "[lexer] %s at line %lu, col %lu : [%s]\n",
			str, tok->pos.line, tok->pos.col, tok->tok);
	return (-1);
}

static inline void		lexical_analysis_ftn(size_t i, char c,
							int step[2][0x20], t_token_exp *exprs)
{
	if (step[0][i] < 0)
		return ;
		next:
	if (exprs[step[0][i]].s[0] == '\0')
		step[0][i] = ((ft_strchr(TOK_DELIM, c) != NULL) || (i == 20) ? -2 : -1);
	else if (ft_strchr(exprs[step[0][i]].s, c) != NULL)
	{
		if (exprs[step[0][i]].reapeatable)
			step[1][i] = 1;
		else
			++(step[0][i]);
	}
	else if (step[1][i] && exprs[step[0][i]].reapeatable)
	{
		step[1][i] = 0;
		++(step[0][i]);
		FT_GOTO(next);
	}
	else
		step[0][i] = -1;
}

/*
** return value:
** 		1 ~ n + 1	the value of the found token + 1
** 		0			tokens are not fully yet analyzed
** 		-1			invalid token
*/

static inline int		all_analyzed(int step[2][0x20],
							t_token_exp **expressions)
{
	FT_INIT(int, found, -1);
	if (FT_FOR(FT_INIT(size_t, i, 0), expressions[i] != NULL, ++i))
	{
		if (step[0][i] >= 0)
			return (0);
		else if (step[0][i] == -2)
			found = (int)i + 1;
	}
	return (found);
}

/*
** return value:
** 		1 ~ n + 1	the value of the found token + 1
** 		0			EOF
** 		-1			invalid token
*/

static inline int		lexical_analysis(int fd, t_token *tok, char *c)
{
	static t_token_exp	**expressions;

	FT_INIT(int, step[2][0x20], NULLARRAY);
	FT_INIT(int, ret, 0);
	FT_INIT(size_t, index, 0);
	FT_INIT(size_t, count, 0);
	if (expressions == NULL)
		expressions = expressions_list();
	if (FT_FOR(count = 0, count < COMMENT_LENGTH + 3, ++count))
	{
		if (FT_FOR(FT_INIT(size_t, i, 0), expressions[i] != NULL, ++i))
			lexical_analysis_ftn(i, *c, step, expressions[i]);
		if ((ret = all_analyzed(step, expressions)))
			break ;
		tok->tok[index++] = *c;
		if ((ret = next_char(fd, c, &(tok->pos))) <= 0)
			return (-128);
	}
	if (count >= COMMENT_LENGTH + 3)
		return (lexer_error("Too long token", tok));
	return (ret);
}

int						lexer(int fd, t_token **token)
{
	static char			c = ' ';
	static t_token		tok;

	FT_INIT(int, ret, 1);
	ft_bzero(tok.tok, COMMENT_LENGTH);
	*token = ft_memdup(&(t_token){tok.pos, "", TOK_TYPE_EOF}, sizeof(t_token));
	while (42)
	{
		if ((ft_strchr(COMMENT_CHAR, c) != NULL) && (ret == 1))
			while (((ret = next_char(fd, &c, &(tok.pos))) > 0) && (c != '\n'))
				;
		else if (ft_strchr(BLANK_CHARS, c))
			;
		else
		{
			(*token)->pos = tok.pos;
			ret = lexical_analysis(fd, &tok, &c);
			ft_strcpy((*token)->tok, tok.tok);
			(*token)->type = (t_token_type)(ret - 1);
			return (ret % 64 < 0 ? lexer_error("Invalid syntax", *token) : ret);
		}
		if ((ret = next_char(fd, &c, &(tok.pos))) <= 0)
			break ;
	}
	return (ret);
}
