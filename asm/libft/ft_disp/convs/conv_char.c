/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 20:12:19 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:36:55 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						conv_e(va_list ap, t_pfflags *flags, char *buff)
{
	static char			c[2] = "?";

	c[0] = flags->char_err;
	if (!c[0])
	{
		--*(flags->index);
		return (-1);
	}
	(void)ap;
	return (format_str(c, flags, buff));
}

int						conv_lchar(va_list ap, t_pfflags *flags, char *buff)
{
	static wchar_t		wc[2] = L"?";

	wc[0] = va_arg(ap, wchar_t);
	if (!wc[0])
	{
		FT_BIT_ON(flags->flg, FTPF_CHAR_0_);
		return (format_str("\0", flags, buff));
	}
	return (format_wstr(wc, flags, buff));
}

int						conv_uchar(va_list ap, t_pfflags *flags, char *buff)
{
	static char			c[2] = "?";

	if (FT_BIT_VAL(flags->flg, FTPF_LONG1))
		return (conv_lchar(ap, flags, buff));
	c[0] = (char)(unsigned char)va_arg(ap, int);
	FT_BIT_ON(flags->flg, FTPF_CHAR_0_);
	return (format_str(c, flags, buff));
}

int						conv_char(va_list ap, t_pfflags *flags, char *buff)
{
	static char			c[2] = "?";

	if (FT_BIT_VAL(flags->flg, FTPF_LONG1))
		return (conv_lchar(ap, flags, buff));
	c[0] = (signed char)va_arg(ap, int);
	FT_BIT_ON(flags->flg, FTPF_CHAR_0_);
	return (format_str(c, flags, buff));
}
