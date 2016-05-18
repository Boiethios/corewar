/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 12:39:56 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/30 12:48:55 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						main(void)
{
	char				*str;
	int					ret;

	ret = ft_asprintf(&str, "Welcome to school %d\n", 42);
	if (str == NULL)
	{
		ft_putstr("memory allocation failed\n");
		return (-1);
	}
	write(1, str, ret);
	ft_putstr(str);
	return (0);
}
