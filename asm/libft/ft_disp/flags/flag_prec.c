/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_prec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 12:20:35 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:48:07 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	In case of negative precision (error), we choose to ignore it
*/

int						flag_prec(t_pfflags *flags, const char *format,
							va_list ap)
{
	int					tmp;

	FT_BIT_ON(flags->flg, FTPF_PRECISION);
	if (format[1] == '*')
	{
		tmp = va_arg(ap, int);
		if (tmp < 0)
			FT_BIT_OFF(flags->flg, FTPF_PRECISION);
		flags->prec = (unsigned)tmp;
		return (2);
	}
	tmp = ft_atoi(format + 1);
	if (tmp < 0)
		FT_BIT_OFF(flags->flg, FTPF_PRECISION);
	flags->prec = (unsigned)tmp;
	return ((signed)ft_nbrlen((intmax_t)flags->prec, 10) +
	((format[1] < '0') || (format[1] > '9') ? 0 : 1));
}
