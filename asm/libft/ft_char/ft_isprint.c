/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:55:42 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/30 15:10:10 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int				ft_isprint(int c)
{
	return ((c >= ' ') && (c <= '~'));
}
