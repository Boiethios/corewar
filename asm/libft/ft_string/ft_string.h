/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:51:11 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/30 16:29:57 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# ifndef LIBFT_H
#  error "Do include libft.h instead"
# endif

/*
** Strings
*/
size_t					ft_strlen(const char *str);
char					*ft_strrev(char *str);

char					*ft_strdup(const char *s1);
char					*ft_strndup(const char *s1, size_t n);

char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t n);
size_t					ft_strlcpy(char *dst, char const *src, size_t size);

char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);

char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);

int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);

char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);

void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(const char *s, char (*f)(char));
char					*ft_strmapi(const char *s, char (*f)(unsigned int,
							char));

int						ft_strequ(const char *s1, const char *s2);
int						ft_strnequ(const char *s1, const char *s2, size_t n);

char					*ft_strsub(const char *s, unsigned int start,
							size_t len);
char					*ft_strjoin(const char *s1, const char *s2);
char					*ft_strtrim(const char *s);
char					**ft_strsplit(char const *s, char const *c);
char					**ft_strsplits(char const *s, char const *c);

int						ft_atoi(const char *str);

char					*ft_strtoupper(char *str);
char					*ft_strtolower(char *str);

size_t					ft_wstrlen(const wchar_t *str);

int						nmatch(char *s1, char *s2);

/*
** get_next_line
**  -> the return value of gnl is the size of line, INCLUDING THE
**     TERMINATING '\0'
*/
# define FT_GNL_MAXFD	256
# define FT_GNL_BUFSIZE	512

typedef struct			s_gnl
{
	char				b[2][FT_GNL_BUFSIZE];
	int					turn;
}						t_gnl;

ssize_t					ft_gnl(const int fd, char **line);

#endif
