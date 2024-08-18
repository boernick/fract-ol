NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c push_swap_input.c push_swap_utils_1.c push_swap_utils_2.c push_swap_utils_3.c\
  push_swap_actions_1.c push_swap_actions_2.c push_swap_sort.c push_swap_do_move.c\$
    push_swap_cases.c push_swap_set_move.c
OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I $(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(HEADER)
        $(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
$
%.o: %.c $(HEADER)
        $(CC) $(CFLAGS) $(INCLUDES) -g -c $< -o $@$
$
$(LIBFT):$
        make -C $(LIBFT_DIR) bonus$
$
clean:$
        rm -f $(OBJS)$
        make -C $(LIBFT_DIR) clean$
$
fclean: clean$
        rm -f $(NAME)$
        make -C $(LIBFT_DIR) fclean$
$
re: fclean all$
$
.PHONY: all clean fclean re
