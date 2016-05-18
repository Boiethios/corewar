/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:28:10 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/11 14:56:35 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_strlcat(char *dst, const char *src, size_t size)
{
	FT_INIT(size_t, i, 0);
	FT_INIT(size_t, len, ft_strlen(dst));
	FT_INIT(char *, tmp, dst + len);
	if (LIBFT_DEBUG && ((dst == NULL) || (src == NULL)))
		ft_errnullptr("ft_strlcat");
	while (src[i] && (len + i < size - 1))
	{
		tmp[i] = src[i];
		++i;
	}
	tmp[i] = '\0';
	return (FT_MIN(len, size) + ft_strlen(src));
}
