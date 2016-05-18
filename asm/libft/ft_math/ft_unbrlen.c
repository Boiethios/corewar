/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 15:20:38 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/11 11:00:11 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned				ft_unbrlen(uint64_t nbr, const size_t base)
{
	unsigned			n;

	n = 1;
	while (nbr /= base)
		++n;
	return (n);
}
