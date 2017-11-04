# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achaussa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/22 19:03:21 by achaussa          #+#    #+#              #
#    Updated: 2017/10/30 15:34:09 by achaussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Werror -Wall -Wextra

LIB = includes/libft/
INC = includes/fillit.h
LIBA = includes/libft/libft.a
SRC = src/check.c src/parse.c src/solve.c src/place.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	gcc -o $(NAME) $(OBJ) $(LIBA) 

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	make -C $(LIB) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIB) fclean
	rm -f $(NAME)

re: fclean all
