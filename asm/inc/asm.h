/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 20:49:43 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 15:51:14 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"

/*
** Lexer configurations
*/

# define FT_ASM_TABSIZE	(4)

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

# define COMMENT_CHAR	";#"
# define LABEL_CHAR		":"
# define DIRECT_CHAR	"%"
# define SEPARATOR_CHAR	","

# define LABEL_CHARS	"abcdefghijklmnopqrstuvwxyz_0123456789"

/*
** Do NOT change those defines ->
*/
# define BLANK_CHARS	" \t\n"

typedef struct			s_token_exp
{
	char				s[128];
	int					reapeatable;
}						t_token_exp;

typedef enum			e_token_type
{
	TOK_TYPE_LIVE,
	TOK_TYPE_LD,
	TOK_TYPE_ST,
	TOK_TYPE_ADD,
	TOK_TYPE_SUB,
	TOK_TYPE_AND,
	TOK_TYPE_OR,
	TOK_TYPE_XOR,
	TOK_TYPE_ZJMP,
	TOK_TYPE_LDI,
	TOK_TYPE_STI,
	TOK_TYPE_FORK,
	TOK_TYPE_LLD,
	TOK_TYPE_LLDI,
	TOK_TYPE_LFORK,
	TOK_TYPE_AFF,
	TOK_TYPE_NAME,
	TOK_TYPE_COM,
	TOK_TYPE_STRING,
	TOK_TYPE_LBL,
	TOK_TYPE_SEP,		// ,
	TOK_TYPE_REG,		// r1
	TOK_TYPE_IND_LBL,	// :lbl
	TOK_TYPE_IND_NBR,	// 1234
	TOK_TYPE_DIR_LBL,	// %:lbl
	TOK_TYPE_DIR_NBR,	// %1234
	TOK_TYPE_EOF,
}						t_token_type;

typedef struct			s_position
{
	size_t				line;
	size_t				col;
}						t_position;

typedef struct			s_token
{
	t_position			pos;
	char				tok[COMMENT_LENGTH + 8 - COMMENT_LENGTH % 4];
	t_token_type		type;

//	int					num;
}						t_token;

typedef struct			s_parser_file
{
	char				*data;
	size_t				size;
	size_t				index;
	// found lbls
	// required lbls
}						t_parser_file;

/*
** functions
*/

int						next_char(int fd, char *c, t_position *pos);

int						lexer(int fd, t_token **tok);
t_token_exp				**expressions_list(void);
char const				*get_token_type_name(t_token_type t);

int						parser(int fd, t_parser_file *file);
int						parse_error(t_token *tok, size_t nargs, ...);

#endif
