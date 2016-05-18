/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:41:15 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/10 18:05:59 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strsub(const char *s, unsigned int start,
							size_t len)
{
	char				*str;

	FT_INIT(size_t, i, 0);
	if (LIBFT_DEBUG && (s == NULL))
		ft_errnullptr("ft_strsub");
	if ((str = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	str[len] = '\0';
	while (i < len)
	{
		str[i] = s[start + i];
		++i;
	}
	return (str);
}
