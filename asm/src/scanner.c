/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:44:13 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/01/26 18:45:53 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#define FT_ASM_READ_BUFFSIZE	(4096)
#define VALID_NOPRINTABLE_CHARS	"\n\t"

static inline char		invalid_char(char c, t_position *pos)
{
	ft_dprintf(2, "[scanner] Invalid character at line %lu, col %lu"
			" : [%s] (code %d)\n",
			pos->line, pos->col,
			(c < 0 ? "non ASCII char" : ft_ascii_name(c)), c);
	return (-1);
}

static inline char		read_error(void)
{
	ft_dprintf(2, "[scanner] %s\n", strerror(errno));
	return (-2);
}

static inline void		init_pos(t_position *pos)
{
	pos->line = 1;
	pos->col = 0;
}

static inline void		update_pos(char c, t_position *pos)
{
	if (c == '\n')
	{
		pos->line++;
		pos->col = 0;
	}
	else if (c == '\t')
		pos->col += FT_ASM_TABSIZE - (pos->col % FT_ASM_TABSIZE);
	else
		pos->col++;
}

/*
** return value:
**		-2	read error
**		-1	invalid char
**		0	end of file
**		1	normal char
**		2	litteral char (precedeed by '\')
*/

int						next_char(int fd, char *c, t_position *pos)
{
	static ssize_t		ret = -1;
	static char			buff[FT_ASM_READ_BUFFSIZE];
	static ssize_t		index = 0;

	if (ret <= 0)
		init_pos(pos);
	if (index >= ret)
	{
		ret = read(fd, buff, FT_ASM_READ_BUFFSIZE);
		if (!ret && pos->col != 0)
			buff[0] = '\n';
		else if (ret <= 0)
			return (!ret ? 0 : read_error());
		index = 0;
	}
	update_pos(buff[index], pos);
	if (!(FT_ISPRINT(buff[index])) &&
			(ft_strchr(VALID_NOPRINTABLE_CHARS, buff[index]) == NULL))
		return (invalid_char(buff[index], pos));
	*c = buff[index++];
	if (*c != '\\')
		return (1);
	*c = buff[index++];
	return (2);
}
