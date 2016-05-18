/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:51:11 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/23 16:59:50 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# ifndef LIBFT_H
#  error "Do include libft.h instead"
# endif

/*
** Geometrie
*/
typedef struct			s_2dpt
{
	int					x;
	int					y;
}						t_2dpt;

typedef struct			s_3dpt
{
	int					x;
	int					y;
	int					z;
}						t_3dpt;

typedef struct			s_mlximg
{
	void				*img_ptr;
	char				*img;
	int					bpp;
	int					lsize;
	int					nlines;
	int					endian;
	int					min;
	int					max;
}						t_mlximg;

void					ft_put_pixel(t_mlximg *datas, t_2dpt *p, int color);
void					ft_put_line(t_mlximg *datas,
							int (*f)(const t_mlximg *datas, const t_matrix *,
							const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2);
void					ft_put_line_octant1(t_mlximg *datas,
							int (*f)(const t_mlximg *datas, const t_matrix *,
							const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2);
void					ft_put_line_octant2(t_mlximg *datas,
							int (*f)(const t_mlximg *datas, const t_matrix *,
							const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2);
void					ft_put_line_octant3(t_mlximg *datas,
							int (*f)(const t_mlximg *datas, const t_matrix *,
							const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2);
void					ft_put_line_octant4(t_mlximg *datas,
							int (*f)(const t_mlximg *datas, const t_matrix *,
							const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2);

/*
** mlx events
*/
void					ft_mlxkey_set(int64_t tabkey[512],
							int index, t_bool value);
int						ft_mlxkey_get(int64_t tabkey[512], int index);

#endif
