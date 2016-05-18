/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:03:14 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/10 17:54:30 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strrchr(char const *s, int c)
{
	char const			*tmp = s + ft_strlen(s);

	if (LIBFT_DEBUG && (s == NULL))
		ft_errnullptr("ft_strrchr");
	while (tmp > s - 1)
	{
		if (*tmp == (char)c)
			return ((char *)(unsigned long)tmp);
		--tmp;
	}
	return (NULL);
}
