/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:05:43 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/30 16:37:45 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define GNL_REMAIN1		remain[fd].b[remain[fd].turn]
#define GNL_REMAIN2		remain[fd].b[!remain[fd].turn]

static ssize_t			rec_gnl(int const fd, char **line, t_gnl *remain,
							size_t index)
{
	char				buff[FT_GNL_BUFSIZE + 1];

	FT_INIT(ssize_t, exitval, (ssize_t)index + 1);
	FT_INIT(ssize_t, ret, read(fd, buff, FT_GNL_BUFSIZE));
	if (ret < 0)
		return (-1);
	buff[ret] = '\0';
	FT_INIT(char *, endl, ft_strchr(buff, '\n'));
	GNL_REMAIN2[0] = '\0';
	if (ret && (endl == NULL))
	{
		exitval = rec_gnl(fd, line, remain, index + (size_t)ret);
		ft_strncpy(*line + index, buff, (size_t)ret);
	}
	else if (!ret && index)
		*line = (char *)malloc((index + 1) * sizeof(char));
	else if (ret)
	{
		exitval = (ssize_t)index + (ssize_t)(endl - buff) + 1;
		*line = (char *)malloc(((size_t)exitval) * sizeof(char));
		ft_strlcpy(*line + index, buff, (size_t)(endl - buff + 1));
		ft_strcpy(GNL_REMAIN2, endl + 1);
	}
	return (!index && !ret ? 0 : exitval);
}

ssize_t					ft_gnl(int const fd, char **line)
{
	static t_gnl		remain[FT_GNL_MAXFD] =
	{[FT_GNL_MAXFD - 1] = {{{'\0'}, {'\0'}}, 0}};
	ssize_t				exitval;
	size_t				len;

	if ((fd < 0) || (fd > FT_GNL_MAXFD - 1))
		return (-1);
	if (*line != NULL)
		ft_memdel((void **)line);
	FT_INIT(char *, endl, ft_strchr(GNL_REMAIN1, '\n'));
	if (endl == NULL)
	{
		len = ft_strlen(GNL_REMAIN1);
		if ((exitval = rec_gnl(fd, line, remain, len)) < 0)
			return (-1);
		ft_memcpy(*line, GNL_REMAIN1, len);
	}
	else
	{
		exitval = (ssize_t)(endl - GNL_REMAIN1) + 1;
		*line = ft_strndup(GNL_REMAIN1, (size_t)(exitval - 1));
		ft_strcpy(GNL_REMAIN2, endl + 1);
	}
	remain[fd].turn = !remain[fd].turn;
	return (exitval);
}
