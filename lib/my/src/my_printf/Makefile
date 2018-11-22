##
## Makefile for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf
## 
## Made by Thomas ARBONA
## Login   <arbona@epitech.net>
## 
## Started on  Tue Nov 15 16:25:33 2016 Thomas ARBONA
## Last update Fri Mar  3 12:24:00 2017 Thomas ARBONA
##

CC	=	clang
CFLAGS	=	-I./include -W -Wall -Wextra

SRC	=	src/fmt/conv/get_nbarg.c	\
		src/fmt/conv/lli_to_str.c	\
		src/fmt/conv/lli_to_octstr.c	\
		src/fmt/conv/lli_to_hexastr.c	\
		src/fmt/conv/lli_to_binstr.c	\
		src/fmt/conv/ptr_to_str.c	\
		src/fmt/conv/char_to_str.c	\
		src/fmt/conv/str_to_str.c	\
		src/fmt/conv/lli_to_basestr.c	\
		src/fmt/flags/flag.c		\
		src/fmt/flags/modif.c		\
		src/fmt/fmt.c			\
		src/fmt/width.c			\
		src/fmt/parser.c		\
		src/fmt/spec.c			\
		src/fmt/pfargs.c		\
		src/my_printf.c			\
		src/my_sprintf.c		\
		src/my_asprintf.c		\
		src/my_snprintf.c		\
		src/my_dprintf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	../my_printf.o

all:		$(NAME)

$(NAME):	$(OBJ)
		ld -o $(NAME) $^ -fPIC -shared

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
