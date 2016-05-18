/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:53:47 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/11 15:34:36 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	FT_INIT(size_t, i, 0);
	FT_INIT(size_t, j, 0);
	FT_INIT(size_t, size_s1, FT_MIN(ft_strlen(s1), n));
	FT_INIT(size_t, size_s2, ft_strlen(s2));
	if (LIBFT_DEBUG && ((s1 == NULL) || (s2 == NULL)))
		ft_errnullptr("ft_strnstr");
	i = 0;
	if (!*s2)
		return ((char *)(unsigned long)s1);
	if (size_s2 > size_s1)
		return (NULL);
	while (i < size_s1 - size_s2 + 1)
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			++j;
			if (!s2[j] || (j > n))
				return ((char *)(unsigned long)(s1 + i));
		}
		++i;
	}
	return (NULL);
}
