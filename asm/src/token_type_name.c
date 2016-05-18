/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 09:57:59 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/01/28 10:17:45 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char const				*get_token_type_name(t_token_type t)
{
	return (((char *[]){
		"LIVE", "LD",
		"ST", "ADD",
		"SUB", "AND",
		"OR", "XOR",
		"ZJMP", "LDI",
		"STI", "FORK",
		"LLD", "LLDI",
		"LFORK", "AFF",
		"NAME", "COMMENT",
		"STRING", "LABEL",
		"SEPARATOR", "REGISTER",
		"INDIRECT LABEL", "INDIRECT NUMBER",
		"DIRECT LABEL", "DIRECT NUMBER",
		"END OF FILE"
	})[t]);
}
