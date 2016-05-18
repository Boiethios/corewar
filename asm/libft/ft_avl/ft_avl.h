/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 14:00:13 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/10 14:47:32 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AVL_H
# define FT_AVL_H

# ifndef LIBFT_H
#  error "Do include libft.h instead"
# endif

# define AVL_FOR(t, i)		1) for(i=ft_avl_min(t); i!=NULL; i=ft_avl_next(t, i)
# define AVL_FORREV(t, i)	1) for(i=ft_avl_max(t); i!=NULL; i=ft_avl_prev(t, i)

struct					s_avl_data
{
	void				*content;
	size_t				size;
};

typedef struct			s_avl_node
{
	struct s_avl_data	data;
	struct s_avl_node	*parent;
	struct s_avl_node	*left;
	struct s_avl_node	*right;
}						t_avl_data;

typedef int				t_avl_fsort(void *a, size_t b, void *c, size_t d);
typedef void			t_avl_ffree(void *a, size_t b);

struct					s_avl
{
	struct s_avl_node	*root;
	t_avl_fsort			fsort;
	t_avl_ffree			ffree;
	size_t				n_elems;
	struct s_avl_node	*min;
	struct s_avl_node	*max;
};

/*
** Usable
*/

typedef struct s_avl	*t_avl;

t_avl					ft_avl_init(t_avl *avl,
							t_avl_fsort fsort, t_avl_ffree ffree);
void					ft_avl_clear(t_avl avl);

int						ft_avl_add(t_avl avl, t_avl_data const *data);
int						ft_avl_del(t_avl avl, t_avl_data const *data);

int						ft_avl_isintree(t_avl avl, t_avl_data const *data);

t_avl_data const		*ft_avl_min(t_avl avl);
t_avl_data const		*ft_avl_max(t_avl avl);
int						ft_avl_cpmin(t_avl avl, t_avl_data *data);
int						ft_avl_cpmax(t_avl avl, t_avl_data *data);

t_avl_data const		*ft_avl_next(t_avl avl, t_avl_data const *tosearch);
t_avl_data const		*ft_avl_prev(t_avl avl, t_avl_data const *tosearch);
int						ft_avl_cpnext(t_avl avl, t_avl_data const *tosearch,
							t_avl_data *data);
int						ft_avl_cpprev(t_avl avl, t_avl_data const *tosearch,
							t_avl_data *data);

#endif
