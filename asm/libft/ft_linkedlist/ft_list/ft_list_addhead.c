/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_addhead.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 15:18:01 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/05/20 15:34:30 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_list_addhead(struct s_list *lst,
							void const *data, size_t size)
{
	struct s_list_link	*link;

	link = p_ft_list_newlink(data, size);
	link->prev = NULL;
	link->next = lst->head;
	if (lst->head != NULL)
		lst->head->prev = link;
	if (lst->tail == NULL)
		lst->tail = link;
	lst->head = link;
	++(lst->len);
}
