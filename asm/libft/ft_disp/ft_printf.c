/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 12:47:08 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/30 12:19:45 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_sprintf(char *buff, const char *format, ...)
{
	va_list				vl;
	int					retval;

	va_start(vl, format);
	retval = ft_vsprintf(buff, format, vl);
	va_end(vl);
	return (retval);
}

int						ft_dprintf(int fd, const char *format, ...)
{
	va_list				vl;
	int					retval;

	va_start(vl, format);
	retval = ft_vdprintf(fd, format, vl);
	va_end(vl);
	return (retval);
}

int						ft_asprintf(char **ret, const char *format, ...)
{
	va_list				vl;
	int					retval;

	va_start(vl, format);
	retval = ft_vasprintf(ret, format, vl);
	va_end(vl);
	return (retval);
}

int						ft_printf(const char *format, ...)
{
	va_list				vl;
	int					retval;

	va_start(vl, format);
	retval = ft_vprintf(format, vl);
	va_end(vl);
	return (retval);
}
