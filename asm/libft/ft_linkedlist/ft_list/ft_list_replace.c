/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 15:18:50 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/05/20 15:54:14 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_list_replace(struct s_list *lst, void *data,
							size_t size, void (*f)(void *, size_t))
{
	struct s_list_link	*link;

	if (lst->cur == NULL)
		return ;
	link = p_ft_list_newlink(data, size);
	link->prev = lst->cur->prev;
	link->next = lst->cur->next;
	if (f != NULL)
		f(lst->cur->data, lst->cur->size);
	else
		free(lst->cur->data);
	free(lst->cur);
	lst->cur = link;
	if (link->prev != NULL)
		link->prev->next = link;
	if (link->next != NULL)
		link->next->prev = link;
}
