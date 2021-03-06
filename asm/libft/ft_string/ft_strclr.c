/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:18:11 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/02/27 14:01:19 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_strclr(char *s)
{
	char				*str;

	if (LIBFT_DEBUG && (s == NULL))
		ft_errnullptr("ft_strclr");
	str = s - 1;
	while (*(++str))
		*str = '\0';
}
