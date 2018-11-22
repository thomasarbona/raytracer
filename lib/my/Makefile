##
## Makefile for D10 in /home/arbona/CPool/CPool_Day10
##
## Made by Thomas Arbona
## Login   <arbona@epitech.net>
##
## Started on  Fri Oct 14 08:34:01 2016 Thomas Arbona
## Last update Mon Mar 13 14:16:53 2017 Thomas ARBONA
##

SRC	=	src/str/my_revstr.c		\
		src/str/my_showstr.c		\
		src/str/my_strcat.c		\
		src/str/my_strcmp.c		\
		src/str/my_strcpy.c		\
		src/str/my_strdup.c		\
		src/str/my_strndup.c		\
		src/str/my_int_str.c		\
		src/str/my_u_int_str.c		\
		src/str/my_str_isalpha.c	\
		src/str/my_str_islower.c	\
		src/str/my_str_isnum.c		\
		src/str/my_str_isprintable.c	\
		src/str/my_str_isupper.c	\
		src/str/my_strlen.c		\
		src/str/my_strncat.c		\
		src/str/my_strncmp.c		\
		src/str/my_str_concat.c		\
		src/str/my_str_template.c	\
		src/str/my_strncpy.c		\
		src/str/my_strstr.c		\
		src/str/my_str_to_wordtab.c	\
		src/str/my_str_contain.c	\
		src/str/my_memset.c		\
		src/str/my_str_replace.c	\
		src/str/my_swapstr.c		\
		src/str/my_getnbr.c		\
		src/str/my_atof.c		\
		src/list/insert.c		\
		src/list/remove.c		\
		src/list/helper.c		\
		src/list/foreach.c		\
		src/tab/my_find_in_wordtab.c	\
		src/tab/my_show_wordtab.c	\
		src/tab/my_sort_int_tab.c	\
		src/tab/my_tablen.c		\
		src/math/convert_base.c		\
		src/math/my_intlen.c		\
		src/math/my_u_intlen.c		\
		src/math/my_find_prime_sup.c	\
		src/math/my_square_root.c	\
		src/math/my_getnbr_base.c	\
		src/math/my_is_prime.c		\
		src/math/my_power_rec.c		\
                src/my_printf/src/fmt/conv/get_nbarg.c        \
                src/my_printf/src/fmt/conv/lli_to_str.c       \
                src/my_printf/src/fmt/conv/lli_to_octstr.c    \
                src/my_printf/src/fmt/conv/lli_to_hexastr.c   \
                src/my_printf/src/fmt/conv/lli_to_binstr.c    \
                src/my_printf/src/fmt/conv/ptr_to_str.c       \
                src/my_printf/src/fmt/conv/char_to_str.c      \
                src/my_printf/src/fmt/conv/str_to_str.c       \
                src/my_printf/src/fmt/conv/lli_to_basestr.c   \
                src/my_printf/src/fmt/flags/flag.c            \
                src/my_printf/src/fmt/flags/modif.c           \
                src/my_printf/src/fmt/fmt.c                   \
                src/my_printf/src/fmt/width.c                 \
                src/my_printf/src/fmt/parser.c                \
                src/my_printf/src/fmt/spec.c                  \
                src/my_printf/src/fmt/pfargs.c                \
                src/my_printf/src/my_printf.c                 \
                src/my_printf/src/my_sprintf.c                \
                src/my_printf/src/my_asprintf.c               \
                src/my_printf/src/my_snprintf.c               \
                src/my_printf/src/my_dprintf.c		\
		src/my_putchar.c		\
		src/my_putnbr_base.c		\
		src/my_put_nbr.c		\
		src/my_putstr.c			\
		src/my_showmem.c		\
		src/my_swap.c			\
		src/my_swapchar.c		\
		src/get_next_line.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc libmy.a $(OBJ)
		cp $(NAME) ../$(NAME)
		mkdir -p ../../include
		cp ./include/my.h ../../include/my.h

clean:
		rm -f $(OBJ) $(OTH_OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -f ../$(NAME)
		rm -f ../../include/my.h

re:		fclean all
