/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_udec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 20:54:25 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:40:53 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				conv_lludec(va_list ap, t_pfflags *flags, char *buff)
{
	unsigned long long int	nbr;

	nbr = va_arg(ap, unsigned long long int);
	return (format_uint((uintmax_t)nbr, flags, buff));
}

int						conv_ludec(va_list ap, t_pfflags *flags, char *buff)
{
	unsigned long int	nbr;

	if (FT_BIT_VAL(flags->flg, FTPF_LONG2) || FT_BIT_VAL(flags->flg, FTPF_J)
			|| FT_BIT_VAL(flags->flg, FTPF_Z))
		return (conv_lludec(ap, flags, buff));
	nbr = va_arg(ap, unsigned long int);
	return (format_uint((uintmax_t)nbr, flags, buff));
}

static int				conv_hhudec(va_list ap, t_pfflags *flags, char *buff)
{
	unsigned char		nbr;

	nbr = (unsigned char)va_arg(ap, int);
	return (format_uint((uintmax_t)nbr, flags, buff));
}

static int				conv_hudec(va_list ap, t_pfflags *flags, char *buff)
{
	short unsigned int	nbr;

	if (FT_BIT_VAL(flags->flg, FTPF_SHORT2))
		return (conv_hhudec(ap, flags, buff));
	nbr = (short unsigned int)va_arg(ap, int);
	return (format_uint((uintmax_t)nbr, flags, buff));
}

int						conv_udec(va_list ap, t_pfflags *flags, char *buff)
{
	unsigned int		nbr;

	if (FT_BIT_VAL(flags->flg, FTPF_J) || FT_BIT_VAL(flags->flg, FTPF_Z))
		return (conv_lludec(ap, flags, buff));
	if (FT_BIT_VAL(flags->flg, FTPF_LONG1))
		return (conv_ludec(ap, flags, buff));
	if (FT_BIT_VAL(flags->flg, FTPF_SHORT1))
		return (conv_hudec(ap, flags, buff));
	nbr = va_arg(ap, unsigned int);
	return (format_uint((uintmax_t)nbr, flags, buff));
}
