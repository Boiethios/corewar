/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 16:20:32 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/30 16:41:16 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strtoupper(char *str)
{
	FT_INIT(FT_REGISTER(char *), s, str);
	while (42)
	{
		*s = FT_TOUPPER(*s);
		if (!*(++s))
			break ;
	}
	return (str);
}
