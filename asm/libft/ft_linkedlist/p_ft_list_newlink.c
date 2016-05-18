/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_list_newlink.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 15:21:29 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/05/20 15:24:20 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct s_list_link		*p_ft_list_newlink(void const *data, size_t size)
{
	struct s_list_link	*link;

	link = ft_memalloc(sizeof(struct s_list_link));
	link->data = malloc(size);
	ft_memcpy(link->data, data, size);
	link->size = size;
	return (link);
}
