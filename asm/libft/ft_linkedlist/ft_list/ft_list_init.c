/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 15:18:21 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/05/20 16:33:28 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list					ft_list_init(t_list *l)
{
	struct s_list		*lst;

	lst = malloc(sizeof(struct s_list));
	if (l != NULL)
		*l = lst;
	lst->cur = NULL;
	lst->tail = NULL;
	lst->head = NULL;
	lst->len = 0;
	return (lst);
}
