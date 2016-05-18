/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 15:18:57 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/18 14:53:07 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int					p_default_list_sort(void const *d1, void const *d2)
{
	return ((int)((char const *)d2 - (char const *)d1));
}

static inline void			ft_list_sort_swap(struct s_list_link *l1,
								t_list_link *l2)
{
	void					*tmp;
	size_t					size;

	tmp = l1->data;
	l1->data = l2->data;
	l2->data = tmp;
	size = l1->size;
	l1->size = l2->size;
	l2->size = size;
}

static inline t_list_link	*ft_list_sort_sorting(struct s_list_link *low,
								struct s_list_link *high,
								int (*f)(const void *, const void *))
{
	struct s_list_link		*tmp;
	struct s_list_link		*arrow;
	void					*median;

	tmp = low->next;
	arrow = low;
	median = low->data;
	while (tmp != high)
	{
		if (f((char *)tmp->data, (char *)median) < 0)
		{
			arrow = arrow->next;
			ft_list_sort_swap(tmp, arrow);
		}
		tmp = tmp->next;
	}
	ft_list_sort_swap(low, arrow);
	return (arrow);
}

static void					ft_list_sort_rec(struct s_list_link *low,
								struct s_list_link *high,
								int (*f)(const void *, const void *))
{
	struct s_list_link		*median;

	if (high == low)
		return ;
	median = ft_list_sort_sorting(low, high, f);
	ft_list_sort_rec(low, median, f);
	ft_list_sort_rec(median->next, high, f);
}

void						ft_list_sort(struct s_list *lst,
								int (*f)(const void *, const void *))
{
	if (f == NULL)
		f = p_default_list_sort;
	ft_list_sort_rec(lst->head, NULL, f);
}
