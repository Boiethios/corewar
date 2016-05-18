/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:22:28 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/11 14:53:21 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strncat(char *s1, const char *s2, size_t n)
{
	FT_INIT(size_t, i, 0);
	FT_INIT(char *, s, s1 + ft_strlen(s1));
	if (LIBFT_DEBUG && ((s1 == NULL) || (s2 == NULL)))
		ft_errnullptr("ft_strncat");
	while (s2[i] && (i < n))
	{
		s[i] = s2[i];
		i++;
	}
	s[i] = '\0';
	return (s1);
}
