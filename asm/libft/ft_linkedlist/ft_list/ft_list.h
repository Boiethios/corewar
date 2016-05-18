/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 14:13:37 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/01/12 17:23:34 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# ifndef LIBFT_H
#  error "Do include libft.h instead"
# endif

# define FTLFD_FTN			t_list_link *
# define FT_LIST_FORD(i, l)	1) for(FTLFD_FTN i = l->head; i != NULL; i = i->next
# define FT_LIST_ROFD(i, l)	1) for(FTLFD_FTN i = l->tail; i != NULL; i = i->prev

# define FTLF_1				1) for(void *i_ =
# define FTLF_2(x)			x = (i_?((t_list_link *)i_)->data:NULL)
# define FTLF_3				; i_ != NULL ; i_ = ((t_list_link *)i_)
# define FT_LIST_FOR(x, l)	FTLF_1 l->head, *FTLF_2(x) FTLF_3->next, FTLF_2(x)
# define FT_LIST_ROF(x, l)	FTLF_1 l->tail, *FTLF_2(x) FTLF_3->prev, FTLF_2(x)

struct					s_list
{
	struct s_list_link	*cur;
	struct s_list_link	*tail;
	struct s_list_link	*head;
	size_t				len;
};

typedef struct s_list	*t_list;

/*
** Initialize a list. Use it before any utilisation.
** Clear a list
*/
t_list					ft_list_init(t_list *lst_p);
void					ft_list_clear(t_list lst_p,
							void (*f)(void *, size_t));

/*
** Add a link in head or in tail.
*/
void					ft_list_addhead(t_list lst,
							void const *data, size_t size);
void					ft_list_addtail(t_list lst,
							void const *data, size_t size);

/*
** Del current link and place current on next (if any).
** Insert before or after current and move it on new ; replace current.
*/
t_list_link				*ft_list_del(t_list lst, void const *data,
							void (*f)(void *, size_t));
void					ft_list_delcur(t_list lst, void (*f)(void *, size_t));
void					ft_list_insbefore(t_list lst,
							void const *data, size_t size);
void					ft_list_insafter(t_list lst,
							void const *data, size_t size);
void					ft_list_replace(t_list lst, void *data, size_t size,
							void (*f)(void *, size_t));

/*
** Move current on next or previous link, if any.
** Move current on head or tail.
*/
int						ft_list_mvnext(t_list lst);
int						ft_list_mvprev(t_list lst);
void					ft_list_mvhead(t_list lst);
void					ft_list_mvtail(t_list lst);

/*
** Util stuff.
*/
void					ft_list_sort(t_list lst,
							int (*f)(void const *, void const *));
void					ft_list_sort_rev(t_list lst,
							int (*f)(void const *, void const *));
size_t					ft_list_len(struct s_list *lst);
void					ft_list_merge(struct s_list *l1, struct s_list *l2);

/*
** Private.
*/
t_list_link				*p_ft_list_del(t_list lst,
							void (*f)(void *, size_t));

#endif
