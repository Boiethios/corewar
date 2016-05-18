/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:06:14 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:30:18 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_H
# define FT_CHAR_H

# ifndef LIBFT_H
#  error "Do include libft.h instead"
# endif

# define FT_ISALPHA(c)	(!((c < 'A') || ((c > 'Z') && (c < 'a')) || (c > 'z')))
# define FT_ISDIGIT(c)	((c >= '0') && (c <= '9'))
# define FT_ISALNUM(c)	(FT_ISALPHA(c) || FT_ISDIGIT(c))
# define FT_ISASCII(c)	(!(c & ~0x7F))
# define FT_ISBLANK(c)	((c == ' ') || (c == '\t'))
# define FT_ISLOWER(c)	((c >= 'a') && (c <= 'z'))
# define FT_ISPRINT(c)	((c >= ' ') && (c <= '~'))
# define FT_ISPUNCT(c)	(FT_ISPRINT(c) && !FT_ISBLANK(c) && !FT_ISALNUM(c))
# define FT_ISSPACE(c)	(FT_ISBLANK(c)||c=='\n'||c=='\v'||c=='\f'||c=='\r')
# define FT_ISUPPER(c)	((c >= 'A') && (c <= 'Z'))

# define FT_TOUPPER(c)	(FT_ISLOWER(c) ? c - 'a' + 'A' : c)
# define FT_TOLOWER(c)	(FT_ISUPPER(c) ? c - 'A' + 'a' : c)

int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_isblank(int c);
int						ft_ispunct(int c);
int						ft_isspace(int c);
int						ft_isupper(int c);
int						ft_islower(int c);

int						ft_toupper(int c);
int						ft_tolower(int c);

char const				*ft_ascii_name(char const code);

#endif
