/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 13:26:10 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 12:00:36 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int		nbits(unsigned int nbr)
{
	register int		i;

	i = 1;
	while (nbr >>= 1)
		i++;
	return (i);
}

static inline int		strwlen(wchar_t const *wstr, t_pfflags *flags)
{
	unsigned int		tmp;
	int					bits;

	FT_INIT(size_t, i, 0);
	FT_INIT(FT_REGISTER(unsigned int), n, 0);
	while (wstr[i])
	{
		tmp = n;
		bits = nbits((unsigned int)wstr[i]);
		if (bits < 8)
			n += 1;
		else if (bits < 12)
			n += 2;
		else if (bits < 17)
			n += 3;
		else
			n += 4;
		if (FT_BIT_VAL(flags->flg, FTPF_PRECISION) && (n > flags->prec))
			return ((signed)tmp);
		++i;
	}
	return ((signed)n);
}

static inline int		cpywchar(const wchar_t wchar, char *str)
{
	int					n;
	int					i;

	i = -1;
	n = nbits((unsigned int)wchar);
	if (n > 7)
	{
		if (n > 11)
		{
			if (n > 16)
			{
				str[++i] = (char)((((unsigned int)wchar >> 18) & 7) | 240);
				str[++i] = (char)((((unsigned int)wchar >> 12) & 63) | 128);
			}
			else
				str[++i] = (char)((((unsigned int)wchar >> 12) & 15) | 224);
			str[++i] = (char)((((unsigned int)wchar >> 6) & 63) | 128);
		}
		else
			str[++i] = (char)((((unsigned int)wchar >> 6) & 31) | 192);
		str[++i] = (char)(((unsigned int)wchar & 63) | 128);
	}
	else
		str[++i] = (char)(wchar);
	return (i + 1);
}

static inline int		write_wstr(const wchar_t *wstr, t_pfflags *flags,
							char *buff)
{
	int					itmp;

	FT_INIT(size_t, i, 0);
	FT_INIT(int, index, -1);
	while (wstr[i])
	{
		itmp = index;
		index += cpywchar(wstr[i], buff + index + 1);
		if (FT_BIT_VAL(flags->flg, FTPF_PRECISION)
				&& ((unsigned)index > flags->prec - 1))
			return (itmp);
		++i;
	}
	return (index);
}

int						format_wstr(const wchar_t *wstr, t_pfflags *flags,
							char *buff)
{
	int					n;
	int					i;
	int					index;
	int					format;

	n = strwlen(wstr, flags);
	format = flags->nformat * (FT_BIT_VAL(flags->flg, FTPF_MINUS) ? -1 : 1);
	i = n - 1;
	index = -1;
	if (format > 0)
		while (++i < format)
			buff[++index] =
				(FT_BIT_VAL(flags->flg, FTPF_ZERO_PADDING) ? '0' : ' ');
	index += write_wstr(wstr, flags, buff + index + 1) + 1;
	i = n - 1;
	if (format < 0)
		while (++i < -format)
			buff[++index] = ' ';
	return (index);
}
