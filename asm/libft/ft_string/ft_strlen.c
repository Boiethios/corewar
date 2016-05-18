/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:28:51 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/10 17:40:11 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LONGPTR_MASK	(sizeof(uint64_t) - 1)

#define MASK01			0x0101010101010101
#define MASK80			0x8080808080808080

static inline size_t	testbytes(register char const *str,
							register char const *p)
{
	if (!p[0])
		return ((unsigned long)p - (unsigned long)str);
	else if (!p[1])
		return ((unsigned long)p - (unsigned long)str + 1);
	else if (!p[2])
		return ((unsigned long)p - (unsigned long)str + 2);
	else if (!p[3])
		return ((unsigned long)p - (unsigned long)str + 3);
	else if (!p[4])
		return ((unsigned long)p - (unsigned long)str + 4);
	else if (!p[5])
		return ((unsigned long)p - (unsigned long)str + 5);
	else if (!p[6])
		return ((unsigned long)p - (unsigned long)str + 6);
	return ((unsigned long)p - (unsigned long)str + 7);
}

size_t					ft_strlen(register char const *str)
{
	register char const	*p = str;
	register uint64_t	*lp;

	if (LIBFT_DEBUG && (str == NULL))
		ft_errnullptr("ft_strlen");
	while ((unsigned long)p & LONGPTR_MASK)
	{
		if (!*p)
			return ((unsigned long)p - (unsigned long)str);
		p++;
	}
	lp = (uint64_t *)(unsigned long)p;
	while (42)
	{
		if ((*lp - MASK01) & MASK80)
			break ;
		lp++;
	}
	return (testbytes(str, (char const *)(unsigned long)lp));
}
