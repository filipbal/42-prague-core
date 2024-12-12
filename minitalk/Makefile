# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 10:38:19 by fbalakov          #+#    #+#             #
#    Updated: 2024/12/12 09:56:16 by fbalakov         ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

# Program names
NAME_CLIENT = client
NAME_SERVER = server

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC_COMMON = ft_printf.c
SRC_CLIENT = client.c
SRC_SERVER = server.c

# Object files
OBJ_COMMON = $(SRC_COMMON:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o) $(OBJ_COMMON)
OBJ_SERVER = $(SRC_SERVER:.c=.o) $(OBJ_COMMON)

# Default target - builds both client and server
all: $(NAME_CLIENT) $(NAME_SERVER)

# Client compilation
$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

# Server compilation
$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

# Rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

# Clean everything
fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

# Rebuild everything
re: fclean all

# These targets don't create files
.PHONY: all clean fclean re