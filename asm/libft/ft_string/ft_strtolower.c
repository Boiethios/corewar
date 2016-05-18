/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 16:42:11 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/30 16:42:28 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strtolower(char *str)
{
	FT_INIT(FT_REGISTER(char *), s, str);
	while (42)
	{
		*s = FT_TOLOWER(*s);
		if (!*(++s))
			break ;
	}
	return (str);
}
