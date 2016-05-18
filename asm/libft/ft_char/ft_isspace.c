/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 17:39:19 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/23 16:57:43 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int				ft_isspace(int c)
{
	return ((c == '\t')
	|| (c == '\n')
	|| (c == '\v')
	|| (c == '\f')
	|| (c == '\r')
	|| (c == ' '));
}
