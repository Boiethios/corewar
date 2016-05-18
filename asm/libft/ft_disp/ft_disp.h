/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:51:11 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/11 16:16:08 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISP_H
# define FT_DISP_H

# ifndef LIBFT_H
#  error "Do include libft.h instead"
# endif

# include "ft_printf.h"

void					ft_putchar(int c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putchar_fd(int c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);

#endif
