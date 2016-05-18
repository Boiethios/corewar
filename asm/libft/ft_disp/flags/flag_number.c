/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:38:57 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/12/11 11:10:21 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						flag_number(t_pfflags *flags, const char *format,
							va_list ap)
{
	flags->nformat = ft_atoi(format);
	(void)ap;
	return ((signed)ft_nbrlen((intmax_t)flags->nformat, 10));
}
