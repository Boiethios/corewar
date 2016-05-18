/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:02:14 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:42:25 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** flag:
** %{c}
**   0	erase all style
**   !	cancel next style (`!u' to cancel underline for example)
** ---
**   b	bold
**   f	faint
**   i	italic
**   u	underline
**   k	blink
**   K	rapid blink
**   r	reverse
**   h	hidden
** ---
**   F	foreground
**   B	background
*/

#define FTPF_STYLEDB	"0bfiukKrh"

static inline void		cancel(t_pfflags *flags, const char *format,
							size_t *i, size_t *j)
{
	static char			style_db[] = FTPF_STYLEDB;

	FT_INIT(char *, place, ft_strchr(style_db, format[++*i]));
	if (place != NULL)
	{
		flags->color[++*j] = '2';
		flags->color[++*j] = '0' + (char)(place - style_db);
	}
	else if (format[*i] == 'F')
	{
		flags->color[++*j] = '3';
		flags->color[++*j] = '9';
	}
	else if (format[*i] == 'B')
	{
		flags->color[++*j] = '4';
		flags->color[++*j] = '9';
	}
}

static inline int		style(t_pfflags *flags, const char *format,
							size_t *i, size_t *j)
{
	static char			style_db[] = FTPF_STYLEDB;

	FT_INIT(char *, place, ft_strchr(style_db, format[*i]));
	if (place != NULL)
		flags->color[++*j] = '0' + (char)(place - style_db);
	else
		return (-1);
	return (0);
}

int						flag_color(t_pfflags *flags, const char *format,
							va_list ap)
{
	FT_INIT(size_t, i, 1);
	FT_INIT(size_t, j, 1);
	while (format[i] && (j < 200))
	{
		if (!style(flags, format, &i, &j))
			;
		else if (format[i] == '!')
			cancel(flags, format, &i, &j);
		else if (format[i] == 'F')
			j += (size_t)ft_sprintf(flags->color + j + 1, "38;5;%d",
					va_arg(ap, int));
		else if (format[i] == 'B')
			j += (size_t)ft_sprintf(flags->color + j + 1, "48;5;%d",
					va_arg(ap, int));
		else
			break ;
		flags->color[++j] = ';';
		++i;
	}
	flags->color[j] = 'm';
	flags->color[++j] = '\0';
	FT_BIT_ON(flags->flg, FTPF_BRACKET_);
	return ((int)i);
}
