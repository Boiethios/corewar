/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 21:27:38 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:49:04 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						flag_short(t_pfflags *flags, const char *format,
							va_list ap)
{
	if (!FT_BIT_VAL(flags->flg, FTPF_SHORT1))
		FT_BIT_ON(flags->flg, FTPF_SHORT1);
	else if (!FT_BIT_VAL(flags->flg, FTPF_SHORT2))
		FT_BIT_ON(flags->flg, FTPF_SHORT2);
	(void)ap;
	(void)format;
	return (1);
}
