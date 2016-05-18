/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/08 14:35:06 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/10 18:38:35 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_power(int nb, int power)
{
	int					n;

	if (power < 0)
		return (0);
	n = 1;
	while (power--)
		n *= nb;
	return (n);
}
