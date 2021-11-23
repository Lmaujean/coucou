# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 14:05:04 by lmaujean          #+#    #+#              #
#    Updated: 2021/11/23 10:54:07 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC= gcc

CFLAGS= -Wall -Wextra -Werror  #-fsanitize=address

RM= rm -f

SRC =	./srcs/main.c\
		./srcs/sort_b.c\
		./srcs/algo_sort.c\
		./srcs/utils_algo2.c\
		./srcs/stack_init_clear.c\
		./srcs/fonction_qui_faut_delete_a_la_fin.c\
		./srcs/move_in_stack.c\
		./srcs/move_in_stack2.c\
		./srcs/sort.c\
		./srcs/utils_algo.c\
		./srcs/error.c\
		./srcs/swap_stack.c\
		./srcs/push_stack.c\
		./srcs/reverse_stack.c\
		./srcs/rotate_stack.c\
		./srcs/utils.c\
		./srcs/utils2.c\

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(OBJ)
	$(RM) $(NAME)
			
reset: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re reset
