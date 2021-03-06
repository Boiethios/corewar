/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/08 19:36:53 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/10 18:39:02 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_sqrt(int nb)
{
	register	int		n;
	register	int		y;
	register	int		z;

	y = 0;
	z = 1;
	n = -1;
	while (y <= nb)
	{
		y += z;
		z += 2;
		n++;
	}
	return (n);
}
