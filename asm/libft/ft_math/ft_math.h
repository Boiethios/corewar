/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:51:11 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/11 10:59:23 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# ifndef LIBFT_H
#  error "Do include libft.h instead"
# endif

/*
** Numbers
*/
int						ft_power(int nb, int power);
int						ft_sqrt(int nb);

unsigned				ft_nbrlen(int64_t nbr, const size_t base);
unsigned				ft_unbrlen(uint64_t nbr, const size_t base);

/*
** Matrix calculation
*/
# define FT_MAT_DIM		4

typedef struct			s_matrix
{
	unsigned int		m;
	unsigned int		n;
	double				tab[FT_MAT_DIM][FT_MAT_DIM];
}						t_matrix;

t_matrix				*ft_mat_new(unsigned char m, unsigned char n,
							double tab[FT_MAT_DIM][FT_MAT_DIM]);
t_matrix				*ft_mat_add(t_matrix *m1, t_matrix *m2, t_matrix *res);
t_matrix				*ft_mat_sub(t_matrix *m1, t_matrix *m2, t_matrix *res);
t_matrix				*ft_mat_mul(t_matrix *m1, t_matrix *m2, t_matrix *res);
void					ft_mat_disp(t_matrix *m);

#endif
