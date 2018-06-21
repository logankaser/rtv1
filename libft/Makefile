# **************************************************************************** # #                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 13:52:57 by lkaser            #+#    #+#              #
#    Updated: 2018/04/19 22:45:23 by lkaser           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
LIST = ft_atof \
ft_atoi \
ft_bzero \
ft_in_range \
ft_isalnum \
ft_isalpha \
ft_isascii \
ft_isdigit \
ft_isprint \
ft_itoa \
ft_itoa_base \
ft_lstadd \
ft_lstdel \
ft_lstdelone \
ft_lstfind \
ft_lstiter \
ft_lstlen \
ft_lstmap \
ft_lstnew \
ft_lstpush \
ft_lstpop \
ft_lstrm \
ft_memalloc \
ft_memccpy \
ft_memchr \
ft_memcmp \
ft_memcpy \
ft_memdel \
ft_memmove \
ft_memset \
ft_putchar \
ft_putchar_fd \
ft_putendl \
ft_putendl_fd \
ft_puterror \
ft_putintarray \
ft_putmem \
ft_putnbr \
ft_putnbr_fd \
ft_putstr \
ft_putstr_fd \
ft_putstrarray \
ft_qsort \
ft_strcat \
ft_strchr \
ft_strclr \
ft_strcmp \
ft_strcpy \
ft_strdel \
ft_strdup \
ft_strequ \
ft_string \
ft_striter \
ft_striteri \
ft_strjoin \
ft_strlcat \
ft_strlen \
ft_strmap \
ft_strmapi \
ft_strncat \
ft_strncmp \
ft_strncpy \
ft_strnequ \
ft_strnew \
ft_strnstr \
ft_strrchr \
ft_strsplit \
ft_strstr \
ft_strsub \
ft_strtrim \
ft_str_has_only \
ft_strprepend \
ft_strappend \
ft_tolower \
ft_toupper \
ft_utoa_base \
ft_wchar_utf8 \
ft_vector \
get_next_line \
ft_printf \
format

SRC = $(addsuffix .c, $(LIST))
OBJ = $(addsuffix .o, $(LIST))

CPPFLAGS = -g -flto -O3 -march=native -Wall -Wextra -Werror -I includes/

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $(OBJ)
	@printf "\e[32;1mlibft.a Created\e[0m\n"

$(OBJ): $(SRC)
	@gcc $(CPPFLAGS) -c $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re

