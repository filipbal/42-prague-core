NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
# This will work for both WSL and Linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Directories
SRC_DIR = src/
LIBFT_DIR = libft/
PRINTF_DIR = ft_printf/
MLX_DIR = minilibx-linux/

# GNL
GNL_DIR = get_next_line/
GNL_FILES = get_next_line.c get_next_line_utils.c
GNL_SRCS = $(addprefix $(GNL_DIR), $(GNL_FILES))

# Source files
SRC_FILES = main.c init.c map.c validate.c render.c events.c utils.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES)) $(GNL_SRCS)
OBJS = $(SRCS:.c=.o)

# Libraries
LIBFT = $(LIBFT_DIR)libft.a
PRINTF = $(PRINTF_DIR)libftprintf.a
MLX = $(MLX_DIR)libmlx.a

# Include directories
INC = -I ./includes -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(MLX_DIR) -I $(GNL_DIR)

# Library flags for linking
LIBS = $(PRINTF) $(LIBFT)

all: $(MLX) $(NAME)

# First compile libft as it's needed by ft_printf
$(LIBFT):
	@echo "Compiling LibFT..."
	@make -C $(LIBFT_DIR)

# Then compile ft_printf which uses libft
$(PRINTF): $(LIBFT)
	@echo "Compiling ft_printf..."
	@make -C $(PRINTF_DIR)

$(MLX):
	@echo "Compiling MinilibX..."
	@make -C $(MLX_DIR)

# Finally compile so_long, which needs both libraries
$(NAME): $(OBJS) $(PRINTF)
	@echo "Compiling $(NAME)..."
	@$(CC) $(OBJS) $(LIBS) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "Compilation complete!"

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	@echo "Cleaning executable and libraries..."
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@rm -f $(MLX)

re: fclean all

.PHONY: all clean fclean re