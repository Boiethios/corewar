/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 12:34:57 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/30 12:50:10 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						main(void)
{
	INIT(int, a, 42);
	INIT(int, b, -123);
	INIT(int, c, 42);
	ft_printf("a = %d ; b = %d ; c = %d\n", a, b, c);
	FT_SWAP(a, b);
	ft_putstr("a <-> b\n");
	ft_printf("a = %d ; b = %d ; c = %d\n", a, b, c);
	FT_SWAP(b, c);
	ft_putstr("b <-> c\n");
	ft_printf("a = %d ; b = %d ; c = %d\n", a, b, c);
}
