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
INCLS =		-I./includes
SRCS_DIR =	srcs
OBJS_DIR =	objs

LIST =	
		
SRCS := $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(LIST)))
OBJS := $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(LIST)))

all: $(NAME)

$(LIB):
	make -C libft/fclean
	make -C libft

$(NAME): $(LIB) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB)
	ranlib $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INLCS) -o $@ -c $<

clean:
	/bin/rm -rf $(OBJS_DIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
