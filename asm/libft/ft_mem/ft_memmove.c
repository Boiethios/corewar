/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:39:39 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/17 18:15:48 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(register void *dst,
								register void const *src,
								register size_t len)
{
	register size_t		i;

	if (LIBFT_DEBUG && ((dst == NULL) || (src == NULL)))
		ft_errnullptr("ft_memmove");
	if ((size_t)dst > (size_t)src)
	{
		i = len;
		while (i > 0)
		{
			--i;
			((char *)dst)[i] = ((char const *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char const *)src)[i];
			++i;
		}
	}
	return (dst);
}
