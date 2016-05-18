/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_prefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 16:49:20 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:48:16 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						flag_prefix(t_pfflags *flags, const char *format,
							va_list ap)
{
	FT_BIT_ON(flags->flg, FTPF_PREFIX);
	(void)ap;
	(void)format;
	return (1);
}
