/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 14:14:26 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/11 14:31:47 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix				*ft_mat_mul(t_matrix *m1, t_matrix *m2, t_matrix *res)
{
	FT_INIT(unsigned int, i, 0);
	FT_INIT(unsigned int, j, 0);
	FT_INIT(unsigned int, k, 0);
	if (res == NULL)
		res = (t_matrix *)malloc(sizeof(t_matrix));
	while (i < m1->n)
	{
		j = 0;
		while (j < m1->n)
		{
			res->tab[i][j] = 0;
			k = 0;
			while (k < m1->n)
			{
				res->tab[i][j] += m1->tab[i][k] * m2->tab[k][j];
				++k;
			}
			++j;
		}
		++i;
	}
	res->m = m2->n;
	res->n = m1->m;
	return (res);
}
