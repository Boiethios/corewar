/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:04:10 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/10 16:26:31 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	register size_t		i;

	if (LIBFT_DEBUG && ((s1 == NULL) || (s2 == NULL)))
		ft_errnullptr("ft_memcmp");
	if (!n)
		return (0);
	i = 0;
	while ((i < n - 1) &&
			(((unsigned const char *)s1)[i] == ((unsigned const char *)s2)[i]))
		i++;
	return ((int)(((unsigned const char *)s1)[i] -
				((unsigned const char *)s2)[i]));
}
