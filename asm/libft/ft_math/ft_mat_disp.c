/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_disp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 14:51:14 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/16 18:15:06 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_mat_disp(t_matrix *mat)
{
	int					i;
	int					j;

	i = -1;
	while (++i < (int)mat->m)
	{
		j = -1;
		write(1, "|\t", 2);
		while (++j < (int)mat->n)
		{
			ft_printf("%d\t", (int)mat->tab[i][j]);
		}
		write(1, "|\n", 2);
	}
}
