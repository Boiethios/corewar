/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 20:56:44 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:49:51 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						flag_zero(t_pfflags *flags, const char *format,
							va_list ap)
{
	FT_BIT_ON(flags->flg, FTPF_ZERO_PADDING);
	(void)ap;
	(void)format;
	return (1);
}
