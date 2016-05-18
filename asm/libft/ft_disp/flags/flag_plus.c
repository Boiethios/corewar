/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 20:58:40 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:47:22 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						flag_plus(t_pfflags *flags, const char *format,
							va_list ap)
{
	FT_BIT_ON(flags->flg, FTPF_PLUS);
	(void)ap;
	(void)format;
	return (1);
}
