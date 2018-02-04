# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkaser <lkaser@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 13:52:57 by lkaser            #+#    #+#              #
#    Updated: 2018/02/03 17:45:45 by dhill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
LIST = rtv1 camera intersect normal cylinder cone \
buffer mlx matrix vector vector_op \
helper parse parse_help

SRC = $(addsuffix .c, $(LIST))
OBJ = $(addsuffix .o, $(LIST))

CPPFLAGS = -I libft/includes -I libmlx
LDFLAGS = -L libft -lft -L libmlx -lmlx -framework OpenGL -framework AppKit
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32;1mLinking.. \033[0m"
	@make -C libft
	@make -C libmlx
	@gcc $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(SRC) -o $(NAME)
	@echo "\033[32;1m"$(NAME)" created\033[0m"

clean:
	@make -C libft clean
	@make -C libmlx clean
	@echo "\033[31;1mCleaning..\033[0m"
	@rm -f $(OBJ)

fclean:
	@make -C libft fclean
	@make -C libmlx fclean
	@echo "\033[31;1mFull Cleaning..\033[0m"
	@rm -f $(OBJ)
	@rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re
