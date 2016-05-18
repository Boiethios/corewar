/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:59:52 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:31:26 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LONGPTR_MASK	(sizeof(uint64_t) - 1)
#define MAGIC_PTR		(char *)0x1

static inline char		*testbytes_ftn(char const *p, const char ch)
{
	if (*++p == ch)
		return ((char *)(unsigned long)p);
	else if (!*p)
		return (NULL);
	if (*++p == ch)
		return ((char *)(unsigned long)p);
	else if (!*p)
		return (NULL);
	if (*++p == ch)
		return ((char *)(unsigned long)p);
	else if (!*p)
		return (NULL);
	if (*++p == ch)
		return ((char *)(unsigned long)p);
	else if (!*p)
		return (NULL);
	return (MAGIC_PTR);
}

static inline char		*testbytes(char const *p, const char ch)
{
	if (*p == ch)
		return ((char *)(unsigned long)p);
	else if (!*p)
		return (NULL);
	if (*++p == ch)
		return ((char *)(unsigned long)p);
	else if (!*p)
		return (NULL);
	if (*++p == ch)
		return ((char *)(unsigned long)p);
	else if (!*p)
		return (NULL);
	if (*++p == ch)
		return ((char *)(unsigned long)p);
	else if (!*p)
		return (NULL);
	return (testbytes_ftn(p, ch));
}

static inline char		*ft_strchr_ftn(const char *s, const char ch)
{
	uint64_t				charmask;
	static const uint64_t	mask = 0x7efefefefefefeff;
	char					*nique_la_norme;

	FT_INIT(FT_REGISTER(uint64_t const *), lp,
			(uint64_t const *)(unsigned long const)s);
	charmask = (uint64_t const)ch | ((uint64_t const)ch << 8);
	charmask |= charmask << 16;
	charmask |= charmask << 32;
	while (42)
	{
		if ((((*lp + mask) ^ ~*lp) & ~mask)
				|| ((((*lp ^ charmask) + mask) ^ ~(*lp ^ charmask)) & ~mask))
		{
			if ((nique_la_norme = testbytes((char const *)lp, ch)) != MAGIC_PTR)
				return (nique_la_norme);
		}
		lp++;
	}
	return (NULL);
}

char					*ft_strchr(const char *s, int c)
{
	FT_INIT(FT_REGISTER(char const *), p, s);
	if (LIBFT_DEBUG && (s == NULL))
		ft_errnullptr("ft_strchr");
	while ((unsigned long)p & LONGPTR_MASK)
	{
		if (*p == (char)c)
			return ((char *)(unsigned long)p);
		else if (!*p)
			return (NULL);
		p++;
	}
	return (ft_strchr_ftn((char *)(unsigned long)p, (char)c));
}
