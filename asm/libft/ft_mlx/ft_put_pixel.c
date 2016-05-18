/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 20:36:57 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/19 10:20:29 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_put_pixel(t_mlximg *datas, t_2dpt *p, int color)
{
	if ((p->x < 0) || (p->y < 0) || (p->y > datas->nlines)
			|| (p->x + 1 > datas->lsize / datas->bpp * 8))
	{
		ft_dprintf(2,
			"%{F}ft_put_pixel: warning: Out of range (%d, %d)%{!F}\n",
			FT_WCOL, p->x, p->y);
		return ;
	}
	datas->img[(datas->lsize * p->y) + datas->bpp / 8 *
		p->x + (datas->endian ? datas->bpp / 8 - 1 : 0)] =
		(char)((color & 0x0000FF) >> 000);
	datas->img[(datas->lsize * p->y) + datas->bpp / 8 *
		p->x + (datas->endian ? datas->bpp / 8 - 2 : 1)] =
		(char)((color & 0x00FF00) >> 010);
	datas->img[(datas->lsize * p->y) + datas->bpp / 8 *
		p->x + (datas->endian ? datas->bpp / 8 - 3 : 2)] =
		(char)((color & 0xFF0000) >> 020);
}
