/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:36:00 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/11 14:48:29 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strmapi(char const *s, char (*f)(unsigned int,
							char))
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
		dst[i] = f((unsigned int)i, s[i]);
		++i;
	}
	return (dst);
}
