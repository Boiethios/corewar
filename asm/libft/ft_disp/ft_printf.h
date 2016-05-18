/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <fdaudre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 19:36:07 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/02/20 12:01:52 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef LIBFT_H
#  error "Do include libft.h first"
# endif

# include <stdarg.h>

/*
** Use it with rgb values from 0 to 5
*/
# define FT_RGBTERM(r, g, b) 16 + b + (g * 6) + (r * 36)

# define FTPF_BUFFSIZE	0x400000
# define FTPF_FT_MAXBASE	32
# define FTPF_ESCAPE	"\033["

int						ft_printf(const char *format, ...);
int						ft_sprintf(char *buff, const char *format, ...);
int						ft_dprintf(int fd, const char *format, ...);
int						ft_asprintf(char **ret, const char *format, ...);

int						ft_vprintf(const char *format, va_list ap);
int						ft_vsprintf(char *buff, const char *format, va_list ap);
int						ft_vdprintf(int fd, const char *format, va_list ap);
int						ft_vasprintf(char **r, const char *format, va_list ap);

/*
** Flags struct: `flags->flg`
*/

enum					e_pf_flags
{
	FTPF_HEX_UPCASE = 1,
	FTPF_ZERO_PADDING,
	FTPF_PLUS,
	FTPF_SPACE,
	FTPF_PREFIX,
	FTPF_LONG1,
	FTPF_LONG2,
	FTPF_MINUS,
	FTPF_SHORT1,
	FTPF_SHORT2,
	FTPF_J,
	FTPF_Z,
	FTPF_PRECISION,
	FTPF_COLOR,
	FTPF_BRACKET_,
	FTPF_CHAR_0_,
	FTPF_FORCE_PREFIX_,
};

typedef struct			s_pfflags
{
	int					*index;

	unsigned int		flg;
	int					nformat;
	unsigned int		prec;

	unsigned int		n_digits;
	char				base;
	char				char_err;
	char				color[254];
}						t_pfflags;

/*
** Funcs database
*/

extern int				(*const g_convs[128])
							(va_list ap, t_pfflags *fl, char *buf);
extern int				(*const g_flags[128])
							(t_pfflags *flags, const char *format, va_list ap);

/*
** format funcs
*/

int						format_str(const char *str, t_pfflags *flags,
							char *buff);
int						format_wstr(const wchar_t *wstr, t_pfflags *flags,
							char *buff);
int						format_int(intmax_t nbr, t_pfflags *flags,
							char *buff);
int						format_uint(uintmax_t nbr, t_pfflags *flags,
							char *buff);

void					write_uint(uintmax_t nbr, char *buff, t_pfflags *flags,
							int *index);
void					write_base(char *buff, int *index, t_pfflags *flags);

/*
** flags.c
**		list of flag functions
*/

int						flag_number(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_prefix(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_long(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_zero(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_plus(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_space(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_minus(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_short(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_j(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_z(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_prec(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_base(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_basemaj(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_star(t_pfflags *flags, const char *format,
							va_list ap);
int						flag_color(t_pfflags *flags, const char *format,
							va_list ap);

/*
** convs.c
**		list of conversion functions
*/

int						conv_e(va_list ap, t_pfflags *flags, char *buf);

int						conv_char(va_list ap, t_pfflags *flags, char *buf);
int						conv_uchar(va_list ap, t_pfflags *flags, char *buf);
int						conv_lchar(va_list ap, t_pfflags *flags, char *buf);
int						conv_int(va_list ap, t_pfflags *flags, char *buf);
int						conv_lint(va_list ap, t_pfflags *flags, char *buf);
int						conv_uoct(va_list ap, t_pfflags *flags, char *buf);
int						conv_luoct(va_list ap, t_pfflags *flags, char *buf);
int						conv_ptr(va_list ap, t_pfflags *flags, char *buf);
int						conv_str(va_list ap, t_pfflags *flags, char *buf);
int						conv_lstr(va_list ap, t_pfflags *flags, char *buf);
int						conv_udec(va_list ap, t_pfflags *flags, char *buf);
int						conv_ludec(va_list ap, t_pfflags *flags, char *buf);
int						conv_uhex(va_list ap, t_pfflags *flags, char *buf);
int						conv_luhex(va_list ap, t_pfflags *flags, char *buf);
int						conv_uhexmaj(va_list ap, t_pfflags *flags, char *buf);
int						conv_color(va_list ap, t_pfflags *flags, char *buf);

#endif
