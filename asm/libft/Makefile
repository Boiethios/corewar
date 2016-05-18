# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/07/15 15:13:38 by fdaudre-          #+#    #+#              #
#    Updated: 2016/01/28 10:52:03 by fdaudre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	Sources
SRCDIR		=	.
SRC			=	\
				ft_char/ft_isalnum.c			\
				ft_char/ft_isalpha.c			\
				ft_char/ft_isascii.c			\
				ft_char/ft_isblank.c			\
				ft_char/ft_isdigit.c			\
				ft_char/ft_islower.c			\
				ft_char/ft_isprint.c			\
				ft_char/ft_ispunct.c			\
				ft_char/ft_isspace.c			\
				ft_char/ft_isupper.c			\
				ft_char/ft_tolower.c			\
				ft_char/ft_toupper.c			\
				ft_char/ft_ascii_name.c			\
				\
				ft_mem/ft_memalloc.c			\
				ft_mem/ft_memccpy.c				\
				ft_mem/ft_memchr.c				\
				ft_mem/ft_memcmp.c				\
				ft_mem/ft_memcpy.c				\
				ft_mem/ft_memdel.c				\
				ft_mem/ft_memmem.c				\
				ft_mem/ft_memmove.c				\
				ft_mem/ft_memdup.c				\
				ft_mem/ft_memset.c				\
				ft_mem/ft_bzero.c				\
				\
				ft_string/ft_strcat.c			\
				ft_string/ft_strchr.c			\
				ft_string/ft_strclr.c			\
				ft_string/ft_strcmp.c			\
				ft_string/ft_strcpy.c			\
				ft_string/ft_strdel.c			\
				ft_string/ft_strdup.c			\
				ft_string/ft_strequ.c			\
				ft_string/ft_striter.c			\
				ft_string/ft_striteri.c			\
				ft_string/ft_strjoin.c			\
				ft_string/ft_strlcat.c			\
				ft_string/ft_strlcpy.c			\
				ft_string/ft_strlen.c			\
				ft_string/ft_wstrlen.c			\
				ft_string/ft_strmap.c			\
				ft_string/ft_strmapi.c			\
				ft_string/ft_strncat.c			\
				ft_string/ft_strncmp.c			\
				ft_string/ft_strncpy.c			\
				ft_string/ft_strndup.c			\
				ft_string/ft_strnequ.c			\
				ft_string/ft_strnew.c			\
				ft_string/ft_strnstr.c			\
				ft_string/ft_strrchr.c			\
				ft_string/ft_strrev.c			\
				ft_string/ft_strsplit.c			\
				ft_string/ft_strsplits.c		\
				ft_string/ft_strstr.c			\
				ft_string/ft_strsub.c			\
				ft_string/ft_strtrim.c			\
				ft_string/ft_atoi.c				\
				ft_string/ft_strtoupper.c		\
				ft_string/ft_strtolower.c		\
				ft_string/ft_nmatch.c			\
				ft_string/ft_gnl.c				\
				\
				ft_math/ft_nbrlen.c				\
				ft_math/ft_unbrlen.c			\
				ft_math/ft_mat_add.c			\
				ft_math/ft_mat_disp.c			\
				ft_math/ft_mat_mul.c			\
				ft_math/ft_mat_new.c			\
				ft_math/ft_mat_sub.c			\
				ft_math/ft_power.c				\
				ft_math/ft_sqrt.c				\
				\
				ft_linkedlist/p_ft_list_newlink.c			\
				\
				ft_linkedlist/ft_list/ft_list_addhead.c		\
				ft_linkedlist/ft_list/ft_list_addtail.c		\
				ft_linkedlist/ft_list/ft_list_clear.c		\
				ft_linkedlist/ft_list/ft_list_del.c			\
				ft_linkedlist/ft_list/ft_list_init.c		\
				ft_linkedlist/ft_list/ft_list_insafter.c	\
				ft_linkedlist/ft_list/ft_list_insbefore.c	\
				ft_linkedlist/ft_list/ft_list_move.c		\
				ft_linkedlist/ft_list/ft_list_replace.c		\
				ft_linkedlist/ft_list/ft_list_sort.c		\
				ft_linkedlist/ft_list/ft_list_sort_rev.c	\
				\
				ft_linkedlist/ft_rlst/ft_rlst_init.c		\
				ft_linkedlist/ft_rlst/ft_rlst_clear.c		\
				\
				ft_disp/ft_putchar.c			\
				ft_disp/ft_putchar_fd.c			\
				ft_disp/ft_putstr.c				\
				ft_disp/ft_putstr_fd.c			\
				ft_disp/ft_putendl.c			\
				ft_disp/ft_putendl_fd.c			\
				ft_disp/ft_printf.c				\
				ft_disp/ft_vprintf.c			\
				ft_disp/init.c					\
				ft_disp/convs/conv_char.c		\
				ft_disp/convs/conv_color.c		\
				ft_disp/convs/conv_int.c		\
				ft_disp/convs/conv_str.c		\
				ft_disp/convs/conv_udec.c		\
				ft_disp/convs/conv_uhex.c		\
				ft_disp/convs/conv_uoct.c		\
				ft_disp/flags/flag_base.c		\
				ft_disp/flags/flag_color.c		\
				ft_disp/flags/flag_j.c			\
				ft_disp/flags/flag_long.c		\
				ft_disp/flags/flag_minus.c		\
				ft_disp/flags/flag_number.c		\
				ft_disp/flags/flag_plus.c		\
				ft_disp/flags/flag_prec.c		\
				ft_disp/flags/flag_prefix.c		\
				ft_disp/flags/flag_short.c		\
				ft_disp/flags/flag_space.c		\
				ft_disp/flags/flag_star.c		\
				ft_disp/flags/flag_z.c			\
				ft_disp/flags/flag_zero.c		\
				ft_disp/forms/format_int.c		\
				ft_disp/forms/format_str.c		\
				ft_disp/forms/format_uint.c		\
				ft_disp/forms/format_wstr.c		\
				ft_disp/forms/write_uint.c		\
				\
				ft_mlx/ft_mlxkey_get.c			\
				ft_mlx/ft_mlxkey_set.c			\
				ft_mlx/ft_put_line2.c			\
				ft_mlx/ft_put_line.c			\
				ft_mlx/ft_put_pixel.c			\
				\
				ft_error/ft_dbg.c				\
				ft_error/ft_errnullptr.c		\
				ft_error/ft_strerror.c			\
				ft_error/ft_syserrlist.c		\

#	Objects
OBJDIR		=	obj

#	Includes
INCDIR		=	-I.

#	Output
NAME		=	libft.a

#	Compiler
CFLAGS		=	-Weverything -Werror
CC			=	cc

#################
##  AUTO       ##
#################

OBJ			=	$(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))
LDFLAGS		=	$(LIBDIR) $(LIB)
NORME		=	**/*.[ch]
VPATH		+=	$(dir $(addprefix $(SRCDIR)/,$(SRC)))

disp_indent	=	for I in `seq 1 $(MAKELEVEL)`; do \
					test "$(MAKELEVEL)" '!=' '0' && printf "\t"; \
				done
color_exec	=	$(call disp_indent); \
				echo "\033["$(1)"m➤"$(3)"\033["$(2)"m";$(3)


#################
##  TARGETS    ##
#################

#	First target
all: $(NAME)

#	Linking
$(NAME): $(OBJ)
	@$(call color_exec,32,31,\
		ar rc $(NAME) $(OBJ))
	@$(call color_exec,32,31,\
		ranlib $(NAME))

#	Objects compilation
$(OBJDIR)/%.o: %.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	@$(call color_exec,36,31,\
		$(CC) $(CFLAGS) $(INCDIR) -o $@ -c $<)

#	Removing objects
clean:
	@$(call color_exec,33,31,\
		rm -rf $(OBJ))
	@rmdir $(OBJDIR) 2> /dev/null || true

#	Removing objects and exe
fclean: clean
	@$(call color_exec,33,31,\
		rm -f $(NAME))

#	All removing then compiling
re: fclean all

#	Checking norme
norme:
	@norminette $(NORME) | sed "s/Norme/[0;1;37m➤ [0;38;5;254mNorme/g;s/Warning/[0;31mWarning/g;s/Error/[0;31mError/g"

codesize:
	@cat $(NORME) |grep -v '/\*' |wc -l

.PHONY: all clean fclean re norme codesize
