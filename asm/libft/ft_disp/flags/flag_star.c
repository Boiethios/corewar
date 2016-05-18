/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_star.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:52:47 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:49:37 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						flag_star(t_pfflags *flags, const char *format,
							va_list ap)
{
	int					n;

	n = va_arg(ap, int);
	flags->nformat = FT_ABS(n);
	if (n < 0)
		FT_BIT_ON(flags->flg, FTPF_MINUS);
	(void)format;
	return (1);
}
