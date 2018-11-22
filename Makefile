##
## Makefile for rt in /home/arbona/tek1/MUL/raytracer1
## 
## Made by Thomas ARBONA
## Login   <thomas.arbona@epitech.eu>
## 
## Started on  Tue Feb 28 15:09:47 2017 Thomas ARBONA
## Last update Sun Mar 19 22:31:31 2017 Thomas ARBONA
##
CC	=	gcc

SRCS	=	src/matrix/init.c		\
		src/matrix/inverse.c		\
		src/matrix/multiply.c		\
		src/matrix/translate.c		\
		src/matrix/rotate.c		\
		src/matrix/copy.c		\
		src/matrix/cross.c		\
		src/matrix/debug.c		\
		src/light/light.c		\
		src/object/object.c		\
		src/object/hit.c		\
		src/object/perlin.c		\
		src/object/sphere/sphere.c	\
		src/object/plane/plane.c	\
		src/object/cylinder/cylinder.c	\
		src/object/cone/cone.c		\
		src/scene/scene.c		\
		src/scene/compute/compute.c	\
		src/scene/compute/light.c	\
		src/scene/compute/reflection.c	\
		src/scene/compute/material.c	\
		src/scene/render.c		\
		src/scene/ray.c			\
		src/scene/vec.c			\
		src/scene/frame/framebuffer.c	\
		src/scene/frame/put_pixel.c	\
		src/scene/parser/core.c		\
		src/scene/parser/obj_setter.c	\
		src/scene/parser/cam_setter.c	\
		src/scene/parser/light_setter.c	\
		src/main.c

CFLAGS	=	-W -Wall -I./include -I./src

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lsfml-graphics -lsfml-window -lsfml-system -lm -L./lib -lmy -lvector -lpthread

OBJS	=	$(SRCS:.c=.o)

NAME	=	raytracer

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
