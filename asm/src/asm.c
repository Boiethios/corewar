/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 20:51:25 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 15:57:09 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>

/*
** Uncomment to active tokenizer debugging
*/
//#define DEBUG_LEXER

#ifndef DEBUG_LEXER

int						main(int argc, char **argv)
{
	int					fd;

	if (argc < 2)
		return (-1);
	if (FT_FOR(FT_INIT(int, i_fd, 1), i_fd < argc, ++i_fd))
	{
		fd = open(argv[i_fd], O_RDONLY);
		FT_INIT(t_parser_file, file, FT_BRACKETS(malloc(0x1000), 0x1000, 0));
		if (file.data)
			(void)parser(fd, &file);
		close(fd);
	}
	return (0);
}

#else

#define PRINT_TOKEN		ft_printf("[lexer] at (%{F}%03lu%{!F}:" \
							"%{F}%03lu%{!F}) : [%{F}%s%{!F}] (%s)\n", \
							FT_RGBTERM(1, 2, 1), tok->pos.line, \
							FT_RGBTERM(1, 2, 1), tok->pos.col, \
							FT_RGBTERM(1, 5, 1), tok->tok, \
							get_token_type_name(tok->type))

int						main(int argc, char **argv)
{
	int					fd;
	t_token				*tok;
	int					ret;

	if (argc < 2)
		return (-1);
	if (FT_FOR(FT_INIT(int, i_fd, 1), i_fd < argc, ++i_fd))
	{
		fd = open(argv[i_fd], O_RDONLY);
		ft_printf("~~ %{r} FILE : %s %{!r} ~~\n", argv[i_fd]);
		while ((ret = lexer(fd, &tok)) > 0)
		{
			PRINT_TOKEN;
			ft_memdel((void **)&tok);
		}
		if (!ret)
			PRINT_TOKEN;
		close(fd);
	}
	return (0);
}

#endif
