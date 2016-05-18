/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 15:10:24 by fdaudre-          #+#    #+#             */
/*   Updated: 2014/12/16 15:47:30 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_wstrlen(const wchar_t *wstr)
{
	size_t				n;

	n = 0;
	while (wstr[n])
		++n;
	return (n);
}
