/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rlst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 14:13:37 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/10 18:45:03 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RLST_H
# define FT_RLST_H

# ifndef LIBFT_H
#  error "Do include libft.h instead"
# endif

# define RLST_FOR(i, l)	1) for(i = l->first; i != NULL; i = l->cur->next

struct					s_rlst
{
	struct s_list_link	*cur;
	struct s_list_link	*first;
	size_t				len;
};

typedef struct s_rlst	*t_rlst;

t_rlst					ft_rlst_init(t_rlst *l);
void					ft_rlst_clear(struct s_rlst *lst,
							void (*f)(void *, size_t));

#endif
