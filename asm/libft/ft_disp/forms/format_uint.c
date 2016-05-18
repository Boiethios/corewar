/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 18:13:35 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:59:42 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int		init(uintmax_t nbr, t_pfflags *flags)
{
	return ((int)((FT_BIT_VAL(flags->flg, FTPF_PRECISION) ?
	FT_MAX(flags->n_digits, flags->prec) :
	flags->n_digits) + ((nbr || FT_BIT_VAL(flags->flg, FTPF_FORCE_PREFIX_))
	&& FT_BIT_VAL(flags->flg, FTPF_PREFIX) ? FT_T((flags->base == 8) ||
	(flags->base == 16), (flags->base == 8) +
	2 * (flags->base == 16), (flags->base > 9) + 2) : 0)));
}

static inline void		write_format_pos(uintmax_t nbr, t_pfflags *flags,
							char *buff, int *index)
{
	int					n;

	n = init(nbr, flags) - 1;
	if (!FT_BIT_VAL(flags->flg, FTPF_ZERO_PADDING))
		while (++n < flags->nformat)
			buff[++*index] = ' ';
	if ((nbr || FT_BIT_VAL(flags->flg, FTPF_FORCE_PREFIX_)) &&
			FT_BIT_VAL(flags->flg, FTPF_PREFIX))
	{
		if ((flags->base == 8) || (flags->base == 16))
			buff[++*index] = '0';
		else
			write_base(buff, index, flags);
		if (flags->base == 16)
			buff[++*index] =
				(FT_BIT_VAL(flags->flg, FTPF_HEX_UPCASE) ? 'X' : 'x');
	}
	if (FT_BIT_VAL(flags->flg, FTPF_ZERO_PADDING))
		while (++n < flags->nformat)
			buff[++*index] = '0';
	write_uint(nbr, buff, flags, index);
}

static inline void		write_format_neg(uintmax_t nbr, t_pfflags *flags,
							char *buff, int *index)
{
	int					n;

	n = init(nbr, flags) - 1;
	if ((nbr || FT_BIT_VAL(flags->flg, FTPF_FORCE_PREFIX_))
			&& FT_BIT_VAL(flags->flg, FTPF_PREFIX))
	{
		if ((flags->base == 8) || (flags->base == 16))
			buff[++*index] = '0';
		else
			write_base(buff, index, flags);
		if (flags->base == 16)
			buff[++*index] =
				(FT_BIT_VAL(flags->flg, FTPF_HEX_UPCASE) ? 'X' : 'x');
	}
	write_uint(nbr, buff, flags, index);
	while (++n < flags->nformat)
		buff[++*index] = ' ';
}

int						format_uint(uintmax_t nbr, t_pfflags *flags, char *buff)
{
	int					index;

	if ((flags->base < 2) || (flags->base > FTPF_FT_MAXBASE))
		return (-1);
	if (FT_BIT_VAL(flags->flg, FTPF_PRECISION))
		FT_BIT_OFF(flags->flg, FTPF_ZERO_PADDING);
	index = -1;
	flags->n_digits = ft_unbrlen(nbr, (size_t)flags->base);
	if (FT_BIT_VAL(flags->flg, FTPF_MINUS))
		write_format_neg(nbr, flags, buff, &index);
	else
		write_format_pos(nbr, flags, buff, &index);
	return (index);
}
