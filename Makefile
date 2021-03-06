# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 11:51:30 by gwoodwar          #+#    #+#              #
#    Updated: 2016/02/23 10:25:11 by gwoodwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# For mem : @ before a commande hide the echo of the command

CC =		clang
FLAGS =		-Wall -Werror -Wextra -O2
NAME =		fdf
INCLS =		-I./includes -I./libft/includes 
LIBFT = 	-L./libft -lft \
			-L./libmlx -lmlx -framework OpenGL -framework AppKit
SRCS_DIR =	srcs
OBJS_DIR =	objs

LIBS =	libft/libft.a \
		libmlx/libmlx.a

LIST =	main \
		parse/get_line \
		misc/print_test \
		mlx/mlx_init \
		mlx/new_image \
		mlx/key_mlx \
		mlx/key_trans \
		mlx/key_hook \
		error/error \
		draw/drawing \
		draw/lines_calc \
		draw/mix_color \
		calcul/vect_proj

SRCS := $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(LIST)))
OBJS := $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(LIST)))

all: $(NAME)

libft/libft.a:
	make -C libft

libmlx/libmlx.a:
	make -C libmlx

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLS) -o $@ -c $<

clean:
	/bin/rm -rf $(OBJS_DIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
