/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:36:27 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/01/28 11:38:48 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

inline int				parse_error(t_token *tok, size_t nargs, ...)
{
	va_list				ap;
	t_token_type		t;

	ft_dprintf(2, "[parser] Syntax error at line %lu, col %lu : [%s] (%s)\n",
			tok->pos.line, tok->pos.col, tok->tok,
			get_token_type_name(tok->type));
	if (!nargs)
		return (-1);
	va_start(ap, nargs);
	ft_dprintf(2, "\t%{b}Expected %s :%{!b!f}\n",
			(nargs > 1 ? "one of those tokens" : "this token"));
	if (FT_FOR(FT_INIT(size_t, i, 0), i < nargs, ++i))
	{
		t = va_arg(ap, t_token_type);
		ft_dprintf(2, "\t  %{b}*%{!b!f}\t%s\n", get_token_type_name(t));
	}
	va_end(ap);
	return (-1);
}
