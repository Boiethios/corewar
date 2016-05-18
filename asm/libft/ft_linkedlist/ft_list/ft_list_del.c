/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 15:33:49 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/01/13 12:50:22 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_list_link		*p_ft_list_del(struct s_list *lst,
							void (*f)(void *, size_t))
{
	FT_INIT(struct s_list_link, *current, lst->cur);
	FT_INIT(t_list_link, *next, current->next);
	if (f != NULL)
		f(current->data, current->size);
	else
		free(current->data);
	if (current->prev == NULL)
	{
		lst->head = current->next;
		lst->head->prev = NULL;
	}
	else if (current->next == NULL)
	{
		lst->tail = current->prev;
		lst->tail->next = NULL;
	}
	else
	{
		current->prev->next = current->next;
		current->next->prev = current->prev;
	}
	free(current);
	--(lst->len);
	return (next);
}

void					ft_list_delcur(struct s_list *lst,
							void (*f)(void *, size_t))
{
	p_ft_list_del(lst, f);
}

t_list_link				*ft_list_del(struct s_list *lst, void const *data,
							void (*f)(void *, size_t))
{
	FT_INIT(struct s_list_link, *tmp, lst->head);
	FT_INIT(struct s_list_link, *tmp2, NULL);
	FT_INIT(struct s_list_link, *ret, NULL);
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		if (tmp->data == data)
		{
			lst->cur = tmp;
			if (ret == NULL)
				ret = p_ft_list_del(lst, f);
			else
				(void)p_ft_list_del(lst, f);
		}
		tmp = tmp2;
	}
	return (ret);
}
