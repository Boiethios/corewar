/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 13:57:14 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/11 10:59:48 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned				ft_nbrlen(int64_t nbr, const size_t base)
{
	unsigned			n;

	n = (nbr < 0 ? 2 : 1);
	while (nbr /= (int)base)
		++n;
	return (n);
}
