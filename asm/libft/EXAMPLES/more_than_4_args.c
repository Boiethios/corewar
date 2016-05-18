/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 15:57:19 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/01/09 15:59:01 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_ARGS(...) __VA_ARGS__
#define MACRO int argc, char **

static void	caca(MACRO argv)
{
	(void)argc;
	(void)argv;
	return ;
}

int			main(int argc, char **argv)
{
	caca(FT_ARGS(argc, argv));
	return (0);
}
