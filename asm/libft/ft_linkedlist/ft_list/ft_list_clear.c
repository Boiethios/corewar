/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 15:18:13 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/05/20 15:18:15 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void		ft_default_free(void *d, size_t s)
{
	free(d);
	(void)s;
}

void					ft_list_clear(struct s_list *lst,
							void (*f)(void *, size_t))
{
	struct s_list_link	*i;
	struct s_list_link	*tmp;

	i = lst->head;
	if (f == NULL)
		f = &ft_default_free;
	while (i != NULL)
	{
		tmp = i->next;
		f(i->data, i->size);
		free(i);
		i = tmp;
	}
	lst->cur = NULL;
	lst->tail = NULL;
	lst->head = NULL;
	lst->len = 0;
}
