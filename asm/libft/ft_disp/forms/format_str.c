/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 15:32:17 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:54:29 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 2	-	padding with '0'
** 128	-	left formating
** ?	-	TODO: cut if FT_ABS(format) < strlen
*/

static inline void		aff_str(const char *str, t_pfflags *flags,
							char *buff, int *index)
{
	FT_INIT(size_t, i, 0);
	if (FT_BIT_VAL(flags->flg, FTPF_CHAR_0_))
		buff[++*index] = str[0];
	else
	{
		while (str[i] && (!FT_BIT_VAL(flags->flg, FTPF_PRECISION)
					|| (i < flags->prec)))
		{
			buff[++*index] = str[i];
			++i;
		}
	}
}

int						format_str(const char *str, t_pfflags *flags,
							char *buff)
{
	size_t				n;
	int					i;
	int					index;
	int					format;

	if (FT_BIT_VAL(flags->flg, FTPF_PRECISION))
		n = (FT_BIT_VAL(flags->flg, FTPF_CHAR_0_) ? 1 :
				FT_MIN((size_t)flags->prec, ft_strlen(str)));
	else
		n = (FT_BIT_VAL(flags->flg, FTPF_CHAR_0_) ? 1 : ft_strlen(str));
	format = flags->nformat * (FT_BIT_VAL(flags->flg, FTPF_MINUS) ? -1 : 1);
	i = (int)n - 1;
	index = -1;
	if (format > 0)
		while (++i < format)
			buff[++index] =
				(FT_BIT_VAL(flags->flg, FTPF_ZERO_PADDING) ? '0' : ' ');
	aff_str(str, flags, buff, &index);
	if (format < 0)
		while (++i < -format)
			buff[++index] = ' ';
	return (index);
}
