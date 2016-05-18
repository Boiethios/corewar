/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:38:09 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/17 14:45:35 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_strlcpy(char *dst, char const *src, size_t size)
{
	FT_INIT(size_t, i, 0);
	while (src[i] && (i < size - 1))
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (i);
}
