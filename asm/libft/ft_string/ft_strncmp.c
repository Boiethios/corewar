/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:21:22 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/11 15:08:44 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_strncmp(const char *s1, const char *s2, size_t n)
{
	FT_INIT(size_t, i, 0);
	FT_INIT(unsigned char const *, ustr1, (unsigned char const *)s1);
	FT_INIT(unsigned char const *, ustr2, (unsigned char const *)s2);
	if (LIBFT_DEBUG && ((s1 == NULL) || (s2 == NULL)))
		ft_errnullptr("ft_strncmp");
	while ((s1[i] == s2[i]) && s1[i] && (i < n - 1))
		i++;
	return ((int)(ustr1[i] - ustr2[i]));
}
