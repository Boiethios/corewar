/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:41:14 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 12:01:12 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				write_rec(uintmax_t nbr, char *buff, t_pfflags *flags,
							int *index)
{
	FT_INIT(uintmax_t, b, (uintmax_t)flags->base);
	if (nbr > b - 1)
		write_rec(nbr / b, buff, flags, index);
	if (nbr % b < 10)
		buff[++*index] = '0' + (char)(nbr % b);
	else
		buff[++*index] = (FT_BIT_VAL(flags->flg, FTPF_HEX_UPCASE) ? 'A' : 'a') +
			(char)(nbr % b) - 10;
}

void					write_uint(uintmax_t nbr, char *buff, t_pfflags *flags,
							int *index)
{
	unsigned int		n;

	if (FT_BIT_VAL(flags->flg, FTPF_PRECISION))
	{
		n = flags->n_digits - 1;
		while (++n < flags->prec)
			buff[++*index] = '0';
	}
	write_rec(nbr, buff, flags, index);
}

void					write_base(char *buff, int *index, t_pfflags *flags)
{
	if (flags->base > 9)
		buff[++*index] = '0' + flags->base / 10;
	buff[++*index] = '0' + flags->base % 10;
	buff[++*index] = (FT_BIT_VAL(flags->flg, FTPF_HEX_UPCASE) ? 'B' : 'b');
}
