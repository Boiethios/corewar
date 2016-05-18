/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 20:55:18 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:41:23 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						conv_ptr(va_list ap, t_pfflags *flags, char *buff)
{
	FT_BIT_ON(flags->flg, FTPF_PREFIX);
	FT_BIT_ON(flags->flg, FTPF_FORCE_PREFIX_);
	flags->base = 16;
	return (conv_ludec(ap, flags, buff));
}

int						conv_luhex(va_list ap, t_pfflags *flags, char *buff)
{
	flags->base = 16;
	return (conv_ludec(ap, flags, buff));
}

int						conv_uhex(va_list ap, t_pfflags *flags, char *buff)
{
	flags->base = 16;
	return (conv_udec(ap, flags, buff));
}

int						conv_uhexmaj(va_list ap, t_pfflags *flags, char *buff)
{
	flags->base = 16;
	FT_BIT_ON(flags->flg, FTPF_HEX_UPCASE);
	return (conv_udec(ap, flags, buff));
}
