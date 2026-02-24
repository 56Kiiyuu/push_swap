NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR		= srcs
OBJ_DIR		= objs
INC_DIR		= inc

SRC_FILES	= \
	main.c \
	parsing/parse_args.c \
	parsing/errors.c \
	parsing/init_stack.c \
	stack/stack_utils.c \
	stack/stack_utils2.c \
	commands/swap.c \
	commands/push.c \
	commands/rotate.c \
	commands/reverse_rotate.c \
	sorting/sort_three.c \
	sorting/sort_stacks.c \
	sorting/init_nodes_a.c \
	sorting/init_nodes_b.c \
	sorting/cheapest.c \
	sorting/position_utils.c \
	utils/ft_atol.c \
	utils/free_split.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)/inc -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
