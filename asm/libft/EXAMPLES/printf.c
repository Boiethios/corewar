/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 11:10:22 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/01/07 11:12:49 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	{!b} is buggy on some term. Use {!f} instead.
*/

int			main(void)
{
	ft_printf("%{b}bold%{!f} - normal\n");
	ft_printf("%{u}underline%{!u} - normal\n");
	ft_printf("%{F}red color%{!F} - normal\n", FT_RGBTERM(5, 0, 0));
	ft_printf("%{F}green color%{!F} - normal\n", FT_RGBTERM(0, 5, 0));
	ft_printf("%{F}blue color%{!F} - normal\n", FT_RGBTERM(0, 0, 5));
	ft_printf("%{F}orange color%{!F} - normal\n", FT_RGBTERM(5, 3, 0));
	ft_printf("%{BF}light blue background%{!B!F} - normal background\n",
			FT_RGBTERM(3, 4, 5), FT_RGBTERM(0, 0, 0));
	return (0);
}
