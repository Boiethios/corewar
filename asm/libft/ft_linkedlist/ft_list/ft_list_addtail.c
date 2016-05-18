/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_addtail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 15:18:06 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/05/20 15:52:59 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_list_addtail(struct s_list *lst,
							void const *data, size_t size)
{
	struct s_list_link	*link;

	link = p_ft_list_newlink(data, size);
	link->next = NULL;
	link->prev = lst->tail;
	if (lst->tail != NULL)
		lst->tail->next = link;
	if (lst->head == NULL)
		lst->head = link;
	lst->tail = link;
	++(lst->len);
}
