/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:27:31 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/11 14:48:20 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strmap(char const *s, char (*f)(char))
{
	char				*dst;

	FT_INIT(size_t, size, ft_strlen(s));
	FT_INIT(size_t, i, 0);
	if (LIBFT_DEBUG && ((s == NULL) || (f == NULL)))
		ft_errnullptr("ft_strmap");
	if ((dst = (char *)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	dst[size] = '\0';
	while (i < size)
	{
		dst[i] = f(s[i]);
		++i;
	}
	return (dst);
}
