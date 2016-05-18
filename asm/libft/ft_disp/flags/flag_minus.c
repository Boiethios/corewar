/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 21:00:44 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:47:05 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						flag_minus(t_pfflags *flags, const char *format,
							va_list ap)
{
	FT_BIT_ON(flags->flg, FTPF_MINUS);
	(void)ap;
	(void)format;
	return (1);
}
