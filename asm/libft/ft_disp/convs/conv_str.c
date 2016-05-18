/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 20:53:41 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:39:27 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						conv_str(va_list ap, t_pfflags *flags, char *buff)
{
	char				*str;

	if (FT_BIT_VAL(flags->flg, FTPF_LONG1))
		return (conv_lstr(ap, flags, buff));
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	return (format_str(str, flags, buff));
}

int						conv_lstr(va_list ap, t_pfflags *flags, char *buff)
{
	wchar_t				*wstr;

	wstr = va_arg(ap, wchar_t *);
	if (wstr == NULL)
		return (format_str("(null)", flags, buff));
	return (format_wstr(wstr, flags, buff));
}
