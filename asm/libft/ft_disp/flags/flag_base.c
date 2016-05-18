/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 13:11:24 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:42:06 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						flag_base(t_pfflags *flags, const char *format,
							va_list ap)
{
	flags->base = (char)ft_atoi(format + 1);
	(void)ap;
	return ((signed)ft_nbrlen((intmax_t)flags->base, 10) + 1);
}

int						flag_basemaj(t_pfflags *flags, const char *format,
							va_list ap)
{
	FT_BIT_ON(flags->flg, FTPF_HEX_UPCASE);
	return (flag_base(flags, format, ap));
}
