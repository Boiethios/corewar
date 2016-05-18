/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:32:33 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/01/20 14:55:17 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char const				*ft_ascii_name(char const code)
{
	static char const	*const database[] = {
		"nul", "soh", "stx", "etx", "eot", "enq", "ack", "bell",
		"backspace", "horizontal tab", "new line", "vertical tab", "new page",
		"cr", "so", "si",
		"dle", "dc1", "dc2", "dc3", "dc4", "nak", "syn", "etb",
		"can", "em", "sub", "escape", "fs", "gs", "rs", "us",
		"space", "!", "\"", "#", "$", "%", "&", "'",
		"(", ")", "*", "+", ",", "-", ".", "/",
		"0", "1", "2", "3", "4", "5", "6", "7",
		"8", "9", ":", ";", "<", "=", ">", "?",
		"@", "A", "B", "C", "D", "E", "F", "G",
		"H", "I", "J", "K", "L", "M", "N", "O",
		"P", "Q", "R", "S", "T", "U", "V", "W",
		"X", "Y", "Z", "[", "\\", "]", "^", "_",
		"`", "a", "b", "c", "d", "e", "f", "g",
		"h", "i", "j", "k", "l", "m", "n", "o",
		"p", "q", "r", "s", "t", "u", "v", "w",
		"x", "y", "z", "{", "|", "}", "~", "del"
	};

	return (database[code % 128]);
}
