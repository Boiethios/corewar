/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 20:12:19 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:39:16 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				conv_llint(va_list ap, t_pfflags *flags, char *buff)
{
	long long int		nbr;

	nbr = va_arg(ap, long long int);
	return (format_int((intmax_t)nbr, flags, buff));
}

int						conv_lint(va_list ap, t_pfflags *flags, char *buff)
{
	long int			nbr;

	if (FT_BIT_VAL(flags->flg, FTPF_LONG2) || FT_BIT_VAL(flags->flg, FTPF_J)
			|| FT_BIT_VAL(flags->flg, FTPF_Z))
		return (conv_llint(ap, flags, buff));
	nbr = va_arg(ap, long int);
	return (format_int((intmax_t)nbr, flags, buff));
}

static int				conv_hhint(va_list ap, t_pfflags *flags, char *buff)
{
	char				nbr;

	nbr = (char)va_arg(ap, int);
	return (format_int((intmax_t)nbr, flags, buff));
}

static int				conv_hint(va_list ap, t_pfflags *flags, char *buff)
{
	short int			nbr;

	if (FT_BIT_VAL(flags->flg, FTPF_SHORT2))
		return (conv_hhint(ap, flags, buff));
	nbr = (short int)va_arg(ap, int);
	return (format_int((intmax_t)nbr, flags, buff));
}

int						conv_int(va_list ap, t_pfflags *flags, char *buff)
{
	int					nbr;

	if (FT_BIT_VAL(flags->flg, FTPF_Z) || FT_BIT_VAL(flags->flg, FTPF_J))
		return (conv_llint(ap, flags, buff));
	if (FT_BIT_VAL(flags->flg, FTPF_LONG1))
		return (conv_lint(ap, flags, buff));
	if (FT_BIT_VAL(flags->flg, FTPF_SHORT1))
		return (conv_hint(ap, flags, buff));
	nbr = va_arg(ap, int);
	return (format_int((intmax_t)nbr, flags, buff));
}
