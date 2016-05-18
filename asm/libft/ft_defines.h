/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 15:03:18 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:32:00 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEFINES_H
# define FT_DEFINES_H

# define LIBFT_DEBUG			0

# define FT_MAX(X, Y)			(X > Y ? X : Y)
# define FT_MIN(X, Y)			(X < Y ? X : Y)
# define FT_SIGN(X)				(X < 0 ? -1 : 1)
# define FT_ABS(X)				(X < 0 ? -X : X)
# define FT_SWAP(X, Y)			if (X != Y) {X = X ^ Y; Y = X ^ Y; X = X ^ Y;}

# define FT_BIT_VAL(nbr, r)		(nbr & (1U << (r - 1)))
# define FT_BIT_ON(nbr, r)		(nbr |= (1U << (r - 1)))
# define FT_BIT_OFF(nbr, r)		(nbr &= ~(1U << (r - 1)))
# define FT_BIT_CMP(n1, n2, r)	(BIT_VAL(n1, r) - BIT_VAL(n2, r))

# define FT_ROT_RIGHT(nbr, r)	((nbr >> r) | (nbr << (sizeof(nbr) - r)))
# define FT_ROT_LEFT(nbr, r)	((nbr << r) | (nbr >> (sizeof(nbr) - r)))

# define FT_FIRST_OCC(str, c)	(int)(ft_strchr(str, c) - str)
# define FT_LAST_OCC(str, c)	(int)(ft_strrchr(str, c) - str)

# define FT_OFFSETOF(type, mb)	((size_t) &((type *)0)->mb)

# define FT_BRACKETS(...)		{__VA_ARGS__}

/*
** for (i = 0; i < 10; i++)	:	if (FOR(i = 0, i < 10, i++))
*/

# define FT_T(expr, yes, no)	(expr ? yes : no)
# define FT_GOTO(lbl)			goto lbl
# define FT_FOR(a, b, c)		1) for (a; b; c
# define FT_DO					1) do
# define FT_WHILE(x)			while(x)
# define FT_SWITCH(x)			1) switch (x
# define FT_CASE(x);			case x:
# define FT_INIT(t, n, val)		t n = val
# define FT_STORE(var, val)		(var = val)
# define FT_ARGS(...)			__VA_ARGS__

# define FT_REGISTER(var)		register var

# define FT_DCOL				25
# define FT_WCOL				202
# define FT_ECOL				196

typedef enum					e_bool
{
	FALSE = 0,
	TRUE
}								t_bool;

#endif
