NAME = fract-ol
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = fractol.c
OBJS = $(SRCS:.c=.o)
HEADER = fract-ol.h

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBX_DIR = minilibx-linux
LIBX = $(LIBX_DIR)/minilibx.a

INCLUDES = -I $(PRINTF_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
		$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(PRINTF) $(LIBX) -o $(NAME)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) $(INCLUDES) -g -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

$(LIBX):
	make -C $(LIBX_DIR)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
