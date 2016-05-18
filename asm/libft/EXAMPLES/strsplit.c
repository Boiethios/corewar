/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 12:04:51 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/01/07 12:11:08 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage:\n\t%s \"sentence to split\"", argv[0]);
		return (-1);
	}
	FT_INIT(size_t, i, 0);
	FT_INIT(char **, tab, ft_strsplit(argv[1], " \t"));
	while (tab[i] != NULL)
	{
		ft_printf("[%2lu] [%s]\n", i, tab[i]);
		++i;
	}
	return (0);
}
