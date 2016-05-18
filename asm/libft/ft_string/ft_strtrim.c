/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:12:33 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/11 14:45:45 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	ft_strtrim_size(const char *s)
{
	FT_INIT(size_t, size, ft_strlen(s) - 1);
	while ((s[size] == ' ') || (s[size] == '\n') || (s[size] == '\t'))
		--size;
	return (size + 1);
}

char					*ft_strtrim(const char *src)
{
	char				*dst;

	FT_INIT(size_t, i, 0);
	FT_INIT(size_t, size, 0);
	if (LIBFT_DEBUG && (src == NULL))
		ft_errnullptr("ft_strtrim");
	while ((*src == ' ') || (*src == '\n') || (*src == '\t'))
		src++;
	if (!*src)
		return (ft_strnew(0));
	size = ft_strtrim_size(src);
	dst = malloc((size + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	dst[size] = '\0';
	while (i < size)
	{
		dst[i] = src[i];
		++i;
	}
	return (dst);
}
