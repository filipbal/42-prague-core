# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 11:19:05 by fbalakov          #+#    #+#              #
#    Updated: 2025/01/13 21:26:48 by fbalakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = src/main.c \
       src/utils/input_validation.c \
       src/utils/input_parse.c \
       src/utils/stack_utils.c \
       src/utils/stack_ops.c \
       src/utils/string_utils.c \
       src/operations/swap_ops.c \
       src/operations/push_ops.c \
       src/operations/rotate_ops.c \
       src/operations/rev_rotate_ops.c \
       src/algorithm/sorting.c \
       src/algorithm/sorting_utils.c

OBJS = $(SRCS:.c=.o)

INCS = -I includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re