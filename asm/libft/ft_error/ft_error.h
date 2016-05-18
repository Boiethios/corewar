/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:51:11 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/01/07 11:13:37 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# ifndef LIBFT_H
#  error "Do include libft.h instead"
# endif

# define FT_DBG			ft_dbg(__FILE__, __LINE__)

extern char const		*const g_syserrlst[];

/*
** Debug
*/
void					ft_dbg(char *file, int line);
void					ft_errnullptr(char const *str) __attribute__
								((noreturn));

/*
** Errors *nix
*/
char const				*ft_strerror(int code);

#endif
