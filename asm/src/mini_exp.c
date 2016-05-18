/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:28:59 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/01/26 18:03:33 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define FT_LEXER_FTN0	"{" LABEL_CHARS "}[" LABEL_CHAR "]"
#define FT_LEXER_FTN1	"[" SEPARATOR_CHAR "]"
#define FT_LEXER_FTN2	"[" LABEL_CHAR "]{" LABEL_CHARS "}"
#define FT_LEXER_FTN3	"[" DIRECT_CHAR "][" LABEL_CHAR "]{" LABEL_CHARS "}"
#define FT_LEXER_FTN4	"[" DIRECT_CHAR "]{-0123456789}"
#define FT_LEXER_FTN5_0	"\"{" BLANK_CHARS "!#$%&'()*+,-./0123456789:;<=>?@"
#define FT_LEXER_FTN5_1	FT_LEXER_FTN5_0 "ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\\\]^_`"
#define FT_LEXER_FTN5	FT_LEXER_FTN5_1 "abcdefghijklmnopqrstuvwxyz{|\\}~}\""

static void				token_exp_assign(t_token_exp *tok, char *begin,
							char *end, int reap)
{
	FT_INIT(size_t, i, 0);
	while (begin != end)
	{
		if ((begin[0] != '\\') || (begin[1] == '\\'))
			tok->s[i++] = *begin;
		++begin;
	}
	tok->s[i] = '\0';
	tok->reapeatable = reap;
}

static t_token_exp		*get_expformat(char *exp)
{
	t_token_exp			exprs[0x100];

	FT_INIT(size_t, n, 0);
	if (FT_FOR(FT_INIT(size_t, i, 0), exp[i], ++i))
	{
		if (exp[i] == '[')
		{
			FT_INIT(size_t, tmp, i + 1);
			while (exp[i] && ((exp[i] != ']') || (exp[i - 1] == '\\')))
				++i;
			token_exp_assign(exprs + n++, exp + tmp, exp + i, 0);
		}
		else if (exp[i] == '{')
		{
			FT_INIT(size_t, tmp, i + 1);
			while (exp[i] && ((exp[i] != '}') || (exp[i - 1] == '\\')))
				++i;
			token_exp_assign(exprs + n++, exp + tmp, exp + i, 1);
		}
		else
			token_exp_assign(exprs + n++, exp + i, exp + i + 1, 0);
	}
	exprs[n++].s[0] = '\0';
	return (ft_memcpy(malloc(n * sizeof(t_token_exp)), exprs,
				n * sizeof(t_token_exp)));
}

static t_token_exp		**get_expressions(char **exp_list)
{
	FT_INIT(size_t, arr_size, 0);
	if (FT_FOR((void)arr_size, exp_list[arr_size] != NULL, ++arr_size))
		;
	FT_INIT(t_token_exp, **ret, malloc(sizeof(t_token_exp *) * (arr_size + 1)));
	if (FT_FOR(FT_INIT(size_t, i, 0), i < arr_size, ++i))
		ret[i] = get_expformat(exp_list[i]);
	ret[arr_size] = NULL;
	return (ret);
}

t_token_exp				**expressions_list(void)
{
	return (get_expressions((char *[]){
		"live", "ld", "st", "add", "sub", "and", "or", "xor",
		"zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff",
		NAME_CMD_STRING,
		COMMENT_CMD_STRING,
		FT_LEXER_FTN5,
		FT_LEXER_FTN0,
		FT_LEXER_FTN1,
		"r{0123456789}",
		FT_LEXER_FTN2,
		"{-0123456789}",
		FT_LEXER_FTN3,
		FT_LEXER_FTN4,
		NULL
	}));
}
