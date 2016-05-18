/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 12:46:51 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/30 12:47:48 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define FT_RESETFLAG(f)	f.flg = 0, f.nformat = 0, f.prec = 0, f.base = 10
#define SAFE_CHAR(c)	(unsigned int)(0x7F & (c))

int						ft_vsprintf(char *buff, const char *format, va_list ap)
{
	static t_pfflags	flags = {NULL, 0, 0, 0, 0, 10, '?', FTPF_ESCAPE};

	FT_INIT(int, i_buff, 0);
	FT_INIT(int, index, 0);
	flags.index = &index;
	while (format[index])
	{
		if (format[index] == '%')
		{
			FT_RESETFLAG(flags);
			while (g_flags[SAFE_CHAR(format[++index])] != NULL)
				index += g_flags[SAFE_CHAR(format[index])]
(&flags, format + index, ap) - 1;
			i_buff += g_convs[SAFE_CHAR(flags.char_err = format[index])]
(ap, &flags, buff + i_buff) + 1;
		}
		else
			buff[i_buff++] = format[index];
		++index;
	}
	buff[i_buff] = '\0';
	return (i_buff);
}

int						ft_vdprintf(int fd, const char *format, va_list ap)
{
	char				buff[FTPF_BUFFSIZE];
	int					retval;

	retval = ft_vsprintf(buff, format, ap);
	write(fd, buff, (size_t)retval);
	return (retval);
}

int						ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

int						ft_vasprintf(char **ret, const char *format, va_list ap)
{
	char				buff[FTPF_BUFFSIZE];
	int					retval;

	retval = ft_vsprintf(buff, format, ap);
	if ((retval < 0) || ((*ret = malloc((size_t)retval + 1)) == NULL))
	{
		*ret = NULL;
		return (-1);
	}
	ft_memcpy(*ret, buff, (size_t)retval + 1);
	return (retval);
}
