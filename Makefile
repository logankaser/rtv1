# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: logan  <logan@42.us.org>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 10:03:24 by logan             #+#    #+#              #
#    Updated: 2018/06/20 22:45:48 by lkaser           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
LIST = rtv1 camera intersect normal cylinder cone \
buffer mlx matrix vector vector_op \
helper parse parse_help

SRC_DIR = src
OBJ_DIR = obj

SRC = $(addsuffix .c, $(addprefix src/, $(LIST)))
OBJ = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(LIST)))
DEP = $(OBJ:%.o=%.d)
CC = clang
SUB = libft libmlx

CPPFLAGS = -Wall -Wextra -Werror \
-I libft/includes -I libmlx \
-Ofast -march=native -flto \
#-g -fsanitize=address -fsanitize=undefined

LDFLAGS = -flto -L libft -lft -L libmlx -lmlx -framework OpenGL -framework AppKit \
#-fsanitize=address -fsanitize=undefined

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	@for s in $(SUB);\
	do\
		make -sC $$s;\
	done
	@printf "\e[32;1mLinking.. \e[0m\n"
	@$(CC) $(LDFLAGS) -o $@ $^
	@printf "\e[32;1mCreated:\e[0m %s\n" $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

-include $(DEP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "\e[34;1mCompiling: \e[0m%s\n" $<
	@$(CC) $(CPPFLAGS) -MMD -c $< -o $@

clean:
	@for s in $(SUB);\
	do\
		make -sC $$s clean;\
	done
	@printf "\e[31;1mCleaning..\e[0m\n"
	@rm -f $(OBJ) $(DEP)

fclean:
	@for s in $(SUB);\
	do\
		make -sC $$s fclean;\
	done
	@printf "\e[31;1mFull Cleaning..\e[0m\n"
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM

re:	fclean all

.PHONY: clean fclean all re
