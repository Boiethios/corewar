/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:50:43 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/10 16:13:44 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	register int		i;

	if (LIBFT_DEBUG && (s == NULL))
		ft_errnullptr("ft_memchr");
	i = -1;
	while (++i < (int)n)
		if (((unsigned char const *)s)[i] == (unsigned char)c)
			return ((void *)(unsigned long)((unsigned char const *)s + i));
	return (NULL);
}
