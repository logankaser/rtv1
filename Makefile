# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkaser <lkaser@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 13:52:57 by lkaser            #+#    #+#              #
#    Updated: 2018/01/22 15:11:33 by lkaser           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
LIST = RTv1 buffer hook matrix vector

SRC = $(addsuffix .c, $(LIST))
OBJ = $(addsuffix .o, $(LIST))

CPPFLAGS = -I libft/includes -I libmlx
LDFLAGS = -L libft -lft -L libmlx -lmlx -framework OpenGL -framework AppKit
CFLAGS = -O3 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
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
