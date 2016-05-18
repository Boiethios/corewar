/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:00:44 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 15:00:07 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

typedef enum			e_arg_code
{
	REG_CODE = 1, // 0b01
	DIR_CODE = 2, // 0b10
	IND_CODE = 3, // 0b11
}						t_arg_code;

# define IND_SIZE		(2)
# define REG_SIZE		(4)
# define DIR_SIZE		REG_SIZE

# define MAX_ARGS_NUMBER	(4)
# define MAX_PLAYERS		(4)
# define MEM_SIZE			(4 * 1024)
# define IDX_MOD			(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)

# define REG_NUMBER		16

# define CYCLE_TO_DIE	1536
# define CYCLE_DELTA	50
# define NBR_LIVE		21
# define MAX_CHECKS		10

/*
** ***** operators table *****
*/

typedef struct			s_op
{
	char				*mnemonic;
	unsigned int		nparams;
	unsigned int		params[3];
	unsigned int		opcode;
	unsigned int		cycles;
	char				*description;
	int					is_byte_code;
	int					is_carry_modif;
}						t_op;

/*
** T_REG	:	register name
** T_DIR	:	direct (pointer) (default: '%')
** T_IND	:	indirect (dereference)
** T_LAB	:	label (adress)
*/

typedef enum			e_arg_type
{
	T_REG = 1,
	T_DIR = 2,
	T_IND = 4,
	T_LAB = 8,
}						t_arg_type;

extern t_op const		g_op_tab[];

/*
** ***** header *****
*/

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	(0xea83f3)

typedef struct			s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH];
}						t_header;

#endif
