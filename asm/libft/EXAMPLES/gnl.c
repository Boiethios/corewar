/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:10:58 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/17 16:16:00 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int						main(int argc, char **argv)
{
	ssize_t				ret;

	FT_INIT(size_t, i, 0);
	if (argc < 2)
		return (ft_printf("Specify a file name\n"));
	FT_INIT(int, fd, open(argv[1], O_RDONLY));
	FT_INIT(char *, line, NULL);
	while ((ret = ft_gnl(fd, &line)) > 0)
	{
		ft_printf("%3u[%02d] %s\n", i, ret, line);
		++i;
	}
	ft_printf("ft_gnl returned %{F}%d%{!F}\n", FT_RGBTERM(0, 3, 4), ret);
	return (0);
}
