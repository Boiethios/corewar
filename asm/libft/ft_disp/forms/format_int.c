/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 18:13:12 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:52:56 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int		init(intmax_t nbr, t_pfflags *flags)
{
	return ((int)((FT_BIT_VAL(flags->flg, FTPF_PRECISION) ?
	FT_MAX(flags->n_digits, flags->prec) : flags->n_digits) + ((nbr < 0)
	|| FT_BIT_VAL(flags->flg, FTPF_PLUS) ||
	FT_BIT_VAL(flags->flg, FTPF_SPACE) ? 1 : 0)
	+ (nbr && FT_BIT_VAL(flags->flg, FTPF_PREFIX)
	? (flags->base > 9) + 2 : 0)));
}

static inline void		write_format_pos(intmax_t nbr, t_pfflags *flags,
							char *buff, int *index)
{
	int					n;

	n = init(nbr, flags) - 1;
	if (!FT_BIT_VAL(flags->flg, FTPF_ZERO_PADDING))
		while ((int)++n < flags->nformat)
			buff[++*index] = ' ';
	if (nbr < 0)
		buff[++*index] = '-';
	else if (FT_BIT_VAL(flags->flg, FTPF_PLUS))
		buff[++*index] = '+';
	else if (FT_BIT_VAL(flags->flg, FTPF_SPACE))
		buff[++*index] = ' ';
	if (nbr && FT_BIT_VAL(flags->flg, FTPF_PREFIX))
		write_base(buff, index, flags);
	if (FT_BIT_VAL(flags->flg, FTPF_ZERO_PADDING))
		while (++n < flags->nformat)
			buff[++*index] = '0';
	write_uint((uintmax_t)FT_ABS(nbr), buff, flags, index);
}

static inline void		write_format_neg(intmax_t nbr, t_pfflags *flags,
							char *buff, int *index)
{
	int					n;

	n = init(nbr, flags) - 1;
	if (nbr < 0)
		buff[++*index] = '-';
	else if (FT_BIT_VAL(flags->flg, FTPF_PLUS))
		buff[++*index] = '+';
	else if (FT_BIT_VAL(flags->flg, FTPF_SPACE))
		buff[++*index] = ' ';
	if (nbr && FT_BIT_VAL(flags->flg, FTPF_PREFIX))
		write_base(buff, index, flags);
	write_uint((uintmax_t)FT_ABS(nbr), buff, flags, index);
	while (++n < flags->nformat)
		buff[++*index] = ' ';
}

int						format_int(intmax_t nbr, t_pfflags *flags, char *buff)
{
	int					index;

	if ((flags->base < 2) || (flags->base > FTPF_FT_MAXBASE))
		return (0);
	if (FT_BIT_VAL(flags->flg, FTPF_PRECISION))
		FT_BIT_OFF(flags->flg, FTPF_ZERO_PADDING);
	index = -1;
	flags->n_digits = ft_unbrlen((uintmax_t)FT_ABS(nbr), (size_t)flags->base);
	if (FT_BIT_VAL(flags->flg, FTPF_MINUS))
		write_format_neg(nbr, flags, buff, &index);
	else
		write_format_pos(nbr, flags, buff, &index);
	return (index);
}
