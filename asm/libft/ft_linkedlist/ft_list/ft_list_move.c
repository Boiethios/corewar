/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 15:18:44 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/05/20 16:00:27 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct s_list;

int						ft_list_mvnext(struct s_list *lst)
{
	struct s_list_link	*link;

	link = lst->cur;
	if (link == NULL)
		return (-1);
	link = link->next;
	if (link == NULL)
		return (-1);
	lst->cur = link;
	return (0);
}

int						ft_list_mvprev(struct s_list *lst)
{
	struct s_list_link	*link;

	link = lst->cur;
	if (link == NULL)
		return (-1);
	link = link->prev;
	if (link == NULL)
		return (-1);
	lst->cur = link;
	return (0);
}

void					ft_list_mvhead(struct s_list *lst)
{
	lst->cur = lst->head;
}

void					ft_list_mvtail(struct s_list *lst)
{
	lst->cur = lst->tail;
}
