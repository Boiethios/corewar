/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:53:31 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:46:55 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						flag_long(t_pfflags *flags, const char *format,
							va_list ap)
{
	if (!FT_BIT_VAL(flags->flg, FTPF_LONG1))
		FT_BIT_ON(flags->flg, FTPF_LONG1);
	else if (!FT_BIT_VAL(flags->flg, FTPF_LONG2))
		FT_BIT_ON(flags->flg, FTPF_LONG2);
	(void)ap;
	(void)format;
	return (1);
}
