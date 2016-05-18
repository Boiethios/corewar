/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 21:32:32 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/10 16:04:22 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	register int		i;

	if (LIBFT_DEBUG && ((dst == NULL) || (src == NULL)))
		ft_errnullptr("ft_memccpy");
	i = 0;
	while ((i < (int)n) && ((unsigned char const *)src)[i] != (unsigned char)c)
	{
		((char *)dst)[i] = ((char const *)src)[i];
		i++;
	}
	if (i == (int)n)
		return (NULL);
	((char *)dst)[i] = (char)c;
	return ((char *)dst + i + 1);
}
