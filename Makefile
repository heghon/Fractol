# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmenant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 13:10:40 by bmenant           #+#    #+#              #
#    Updated: 2019/06/14 11:47:18 by bmenant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_FILE = ./src/
OBJ_FILE = ./obj/

SRCS =	main.c \
		fractol_define_window.c \
		fractol_drawing.c \
		fractol_julia_handler.c \
		fractol_key_handler.c \
		fractol_mandelbrot_handler.c \
		fractol_mouse_handler.c \
		fractol_newton_handler.c \
		fractol_ship_handler.c \
		fractol_type_writer.c


OBJS = $(SRCS:.c=.o)

SRC = $(addprefix $(SRC_FILE),$(SRCS))
OBJ = $(addprefix $(OBJ_FILE),$(OBJS))

FLAGS = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I./includes/
LFLAGS = ./libft/libft.a

CC = gcc $(CFLAGS)

.PHONY: all, clean, fclean, re

all : $(NAME)

$(NAME) : $(OBJ)
	@ make -C./libft/
	@ $(CC) $(LFLAGS) $(OBJ) -o $@ $(FLAGS)

$(OBJ_FILE)%.o : $(SRC_FILE)%.c
	@ mkdir $(OBJ_FILE) 2> /dev/null || true
	@ $(CC) $(IFLAGS) -o $@ -c $<

clean :
	@ make clean -C ./libft/
	@ rm -f $(OBJ)
	@ rmdir $(OBJ_FILE) 2> /dev/null || true

fclean : clean
	@ make fclean -C ./libft/
	@ rm -f $(NAME)

re	: fclean all

test : re
	@ ./$(NAME)
