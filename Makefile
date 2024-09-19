# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 15:47:19 by kamillarazi       #+#    #+#              #
#    Updated: 2024/07/20 18:02:32 by krazikho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

MAIN = push_swap.c
STACK = stack/fillthestack.c stack/listutils.c stack/ps_atoi.c stack/ps_split.c stack/free_error.c 
OPR = operations/push_rotate.c  operations/rrotate.c operations/swap.c
ALGO = algo/algorithm.c algo/setparameters.c
CHECKER_SRCS = bonus/push_swap_bonus.c bonus/checkerutils.c bonus/push_rotate_bonus.c bonus/swap_bonus.c bonus/rrotate_bonus.c
GET_NEXT_LINE = bonus/gnl/get_next_line.c bonus/gnl/get_next_line_utils.c

OBJS = $(MAIN:.c=.o) $(STACK:.c=.o) $(OPR:.c=.o) $(ALGO:.c=.o)
CHECK_OBJS = $(STACK:.c=.o) ${CHECKER_SRCS:.c=.o} ${GET_NEXT_LINE:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: ${CHECK_OBJS} 
	${CC} ${CFLAGS} -o $(CHECKER) ${CHECK_OBJS}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	 rm -rf $(OBJS) $(CHECK_OBJS)

fclean: clean
	rm -rf $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re