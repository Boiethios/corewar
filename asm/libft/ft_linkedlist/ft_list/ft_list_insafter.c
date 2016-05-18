/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insafter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 15:18:26 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/05/20 16:34:05 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct s_list;

static inline void		p_ft_list_insafter(t_list lst,
							t_list_link *link)
{
	lst->cur = link;
	lst->head = link;
	lst->tail = link;
}

void					ft_list_insafter(t_list lst,
							void const *data, size_t size)
{
	struct s_list_link	*current;
	struct s_list_link	*link;

	current = lst->cur;
	link = p_ft_list_newlink(data, size);
	if (current == NULL)
		p_ft_list_insafter(lst, link);
	else if (current->next == NULL)
	{
		lst->tail = link;
		link->prev = current;
		current->next = link;
	}
	else
	{
		link->prev = current;
		link->next = current->next;
		link->next->prev = link->prev;
		link->prev->next = link->next;
	}
	lst->cur = link;
	++(lst->len);
}
