/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 10:49:46 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/01/28 10:55:10 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memdup(register void const *src,
								register size_t n)
{
	register char		*dst;

	if (LIBFT_DEBUG && (src == NULL))
		ft_errnullptr("ft_memdup");
	if ((dst = malloc(n)) == NULL)
		return (NULL);
	return (ft_memmove(dst, src, n));
}
