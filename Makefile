# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darian <darian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 21:07:30 by darian            #+#    #+#              #
#    Updated: 2022/01/24 18:37:47 by darian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = src/main.c src/generate_operation.c src/little_list_utils.c src/push_swap_utils.c src/push_swap_utils_2.c src/five_numbers_four_la.c src/push_swap_utils_3.c src/five_numbers.c src/five_numbers_operation.c src/three_numbers.c src/median.c src/push_swap.c src/push.c src/rotate.c src/reverse_rotate.c src/swap.c src/little_list.c src/visualizer.c src/error.c src/operations.c src/array.c

all :
	make -C libft
	gcc -g3 -Wall -Wextra -Werror $(SRC) libft/libft.a -o $(NAME)

clean :
	make clean -C libft
	rm -rf src/main.o

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)

re : fclean all
