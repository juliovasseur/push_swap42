# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 17:09:26 by jvasseur          #+#    #+#              #
#    Updated: 2023/03/25 17:16:20 by jvasseur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang -gdwarf-4 -g

CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

NAME_BONUS = checker

SRC = src/create_tab_arg.c src/parsing.c src/parsing_two.c src/instruction_two.c src/lst_utils.c src/utils.c src/utils_two.c src/utils_tree.c src/instruction.c src/sort_in_tab.c

SRC_MAIN_PUSH = src/push_swap.c

SRC_BONUS = src_bonus/checker_exec_bonus.c src_bonus/main_checker_bonus.c src_bonus/parsing_checker_bonus.c src_bonus/create_tab_arg_bonus.c src_bonus/parsing_bonus.c src_bonus/parsing_two_bonus.c src_bonus/instruction_two_bonus.c src_bonus/lst_utils_bonus.c src_bonus/instruction_bonus.c src_bonus/sort_in_tab_bonus.c src_bonus/utils_bonus.c 

MAKE = make -C

OBJ = $(SRC:.c=.o) $(SRC_MAIN_PUSH:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME) : $(OBJ)
	$(MAKE) Libft
	$(CC) $(CFLAGS) $(SRC) $(SRC_MAIN_PUSH) -o $(NAME) -LLibft -lft -LLibft/ft_printf -lftprintf

bonus : ${OBJ} ${OBJ_BONUS}
	$(MAKE) Libft
	$(CC) $(CFLAGS) $(SRC_BONUS) -o $(NAME_BONUS) -LLibft -lft -LLibft/ft_printf -lftprintf
	
all : $(NAME)

clean :
	make -C Libft clean
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	make -C Libft fclean
	rm -f $(NAME) $(NAME_BONUS)


re : fclean all

.PHONY : all clean fclean re
