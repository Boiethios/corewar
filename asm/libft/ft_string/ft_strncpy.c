/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:11:37 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/11 16:30:31 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strncpy(char *dst, const char *src, size_t n)
{
	FT_INIT(size_t, i, 0);
	if (LIBFT_DEBUG && ((dst == NULL) || (src == NULL)))
		ft_errnullptr("ft_strncpy");
	while ((i < n) && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dst[i] = '\0';
		++i;
	}
	return (dst);
}
