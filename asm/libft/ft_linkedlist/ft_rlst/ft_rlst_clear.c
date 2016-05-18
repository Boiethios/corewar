/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rlst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 15:14:15 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/05/20 16:32:40 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void		ft_default_free(void *d, size_t s)
{
	free(d);
	(void)s;
}

void					ft_rlst_clear(struct s_rlst *lst,
							void (*f)(void *, size_t))
{
	struct s_list_link	*i;
	struct s_list_link	*end;
	struct s_list_link	*tmp;

	i = lst->first;
	end = lst->first;
	if (f == NULL)
		f = &ft_default_free;
	while (42)
	{
		tmp = i->next;
		f(i->data, i->size);
		free(i);
		i = tmp;
		if (i == end)
			break ;
	}
	lst->cur = NULL;
	lst->first = NULL;
	lst->len = 0;
}
