# NAME = so_long
CC = gcc
CFLAGS = -fsanitize=address -Wall -Wextra -Werror -ggdb
INCLUDES = -Iincludes -Ilib/libft -Ilib/ft_printf -Ilib/GetNextLine/Mandatory -Ilib/minilibx_macos

# Source files
SCRS_DIR = srcs
MAIN_DIR = main
UTILS_DIR = utils
SRCS_FILES = $(addprefix $(MAIN_DIR)/, main.c init.c) \
						 $(addprefix $(UTILS_DIR)/, error.c map_checker.c map_utils.c parse_check.c) \

SRCS = $(addprefix $(SRCS_DIR)/,$(SRCS_FILES))

# Object files
OBJS_DIR = objs
OBJS_DIRS = $(OBJS_DIR) $(OBJS_DIR)/$(MAIN_DIR) $(OBJS_DIR)/$(UTILS_DIR)
OBJS_FILES = $(patsubst %.c,%.o,$(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR)/,$(OBJS_FILES))

# Librairies
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINF_DIR = lib/ft_printf
PRINTF = $(PRINF_DIR)/libftprintf.a

GNL_DIR = lib/GetNextLine
GNL = $(GNL_DIR)/gnl.a
# MINILIBX_DIR = lib/minilibx
# MINILIBX = $(MINILIBX_DIR)/libmlx.a

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
LIBS = -L$(LIBFT_DIR) -L$(PRINF_DIR) -L$(GNL_DIR) -lft -lftprintf

#Binary
NAME = so_long

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m
RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
UNDERLINE = \033[4m
BLINK = \033[5m
INVERT = \033[7m
LIGHT_BLUE = \033[94m
YELLOW = \033[33m

# Makefile rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL)
		@echo "$(YELLOW)Compiling $(NAME)$(NC)"
		@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)
		@echo "$(GREEN)$(BOLD)$(NAME) has been created$(NC)"

$(OBJS_DIR)/%.o: $(SCRS_DIR)/%.c
		@mkdir -p $(OBJS_DIRS)
		@echo "$(BOLD)$(YELLOW)Compiling $<...$(RESET)"
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
		@echo "$(YELLOW)Compiling libft...$(RESET)"
		@make -C $(LIBFT_DIR) -s

$(PRINTF):
		@echo "$(YELLOW)Compiling ft_printf...$(RESET)"
		@make -C $(PRINF_DIR) -s

$(GNL):
		@echo "$(YELLOW)Compiling GetNextLine...$(RESET)"
		@make -C $(GNL_DIR) -s

$(MINILIBX):
		@echo "$(YELLOW)Compiling minilibx...$(RESET)"

clean:
		@echo "$(RED)Cleaning objects...$(NC)"
		@rm -rf $(OBJS_DIR)
		@make -C $(LIBFT_DIR) clean -s
		@make -C $(PRINF_DIR) clean -s
		@make -C $(GNL_DIR) clean -s

fclean: clean
		@echo "$(RED)Cleaning $(NAME)...$(NC)"
		@rm -f $(NAME)
		@make -C $(LIBFT_DIR) fclean -s
		@make -C $(PRINF_DIR) fclean -s
		@make -C $(GNL_DIR) fclean -s

re: fclean all

.PHONY: all clean fclean re