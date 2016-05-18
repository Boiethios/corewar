/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:02:12 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:37:43 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						conv_color(va_list ap, t_pfflags *flags, char *buff)
{
	static char			c[2] = "}";

	if (!FT_BIT_VAL(flags->flg, FTPF_BRACKET_))
	{
		FT_BIT_ON(flags->flg, FTPF_CHAR_0_);
		return (format_str(c, flags, buff));
	}
	FT_BIT_OFF(flags->flg, FTPF_BRACKET_);
	(void)ap;
	return (format_str(flags->color, flags, buff));
}
