/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insbefore.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 15:18:34 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/05/20 16:34:12 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void		p_ft_list_insbefore(t_list lst,
							t_list_link *link)
{
	lst->cur = link;
	lst->head = link;
	lst->tail = link;
}

void					ft_list_insbefore(t_list lst,
							void const *data, size_t size)
{
	struct s_list_link	*current;
	struct s_list_link	*link;

	current = lst->cur;
	link = p_ft_list_newlink(data, size);
	if (current == NULL)
		p_ft_list_insbefore(lst, link);
	else if (current->prev == NULL)
	{
		lst->head = link;
		link->next = current;
		current->prev = link;
	}
	else
	{
		link->next = current;
		link->prev = current->prev;
		link->next->prev = link->prev;
		link->prev->next = link->next;
	}
	lst->cur = link;
	++(lst->len);
}
