/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:23:13 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/05/20 15:20:11 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memset(register void *b,
							register int c, size_t olol)
{
	register size_t		i;
	register size_t		len;

	len = olol;
	if (LIBFT_DEBUG && (b == NULL))
		ft_errnullptr("ft_memset");
	i = 0;
	while (i < len)
	{
		((char *)b)[i] = (char)(unsigned char)c;
		++i;
	}
	return (b);
}
