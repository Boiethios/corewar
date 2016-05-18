/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rlst_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 16:32:09 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/05/20 16:38:18 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rlst					ft_rlst_init(t_rlst *l)
{
	struct s_rlst		*lst;

	lst = malloc(sizeof(struct s_rlst));
	if (l != NULL)
		*l = lst;
	lst->cur = NULL;
	lst->first = NULL;
	lst->len = 0;
	return (lst);
}
