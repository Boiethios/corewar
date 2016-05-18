/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:57:49 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/01/07 13:57:28 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						main(void)
{
	char				*line;
	t_list				lst;

	ft_printf(">> %{F}Enter some words, type ^D to quit%{!F}\n", 123);
	ft_list_init(&lst);
	line = NULL;
	while (ft_gnl(0, &line) > 0)
		ft_list_insafter(lst, STRDATA(line));
	ft_list_sort_rev(lst, LSTSORT(&ft_strcmp));
	ft_putstr(">> Sorted by dictionary order\n");
	if (FT_LIST_ROF(i, lst))
		ft_printf("%s\n", i);
	ft_putstr(">> Sorted by dictionary reverse order\n");
	if (FT_LIST_FOR(i, lst))
		ft_printf("%s\n", i);
	return (0);
}
