/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_j.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 21:30:17 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 11:42:38 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						flag_j(t_pfflags *flags, const char *format,
							va_list ap)
{
	FT_BIT_ON(flags->flg, FTPF_J);
	(void)ap;
	(void)format;
	return (1);
}
