/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkedlist_defines.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 16:35:15 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/18 14:50:25 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINKEDLIST_DEFINES_H
# define FT_LINKEDLIST_DEFINES_H

# ifndef LIBFT_H
#  error "Do include libft.h instead"
# endif

# define LSTDATA(l,tp)	((tp)(l->data))
# define STRDATA(str)	str, ft_strlen(str) + 1
# define LSTSORT(fnc)	((int (*)(void const *, void const *))fnc)

typedef struct			s_list_link
{
	void				*data;
	size_t				size;
	struct s_list_link	*next;
	struct s_list_link	*prev;
}						t_list_link;

struct s_list_link		*p_ft_list_newlink(void const *data, size_t size);

#endif
