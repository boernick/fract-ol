NAME = fract-ol
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = fractol.c fractol_utils.c fractol_math.c fractol_events.c
OBJS = $(SRCS:.c=.o)
HEADER = fract-ol.h

PRINTF_DIR = includes/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBX_DIR = includes/minilibx-linux
LIBX = $(LIBX_DIR)/libmlx.a
LIBFT_DIR = includes/Libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I $(PRINTF_DIR) -I $(LIBX_DIR) -I $(LIBFT_DIR)

MLX_LIBS = -L$(LIBX_DIR) -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF) $(LIBFT) $(LIBX)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(PRINTF) $(LIBFT) $(LIBX) $(MLX_LIBS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -g -c $< -o $@

$(LIBFT): 
	make -C $(LIBFT_DIR) bonus

$(PRINTF): $(LIBFT)
	make -C $(PRINTF_DIR)

$(LIBX):
	make -C $(LIBX_DIR)

clean:
	rm -f $(OBJS)
	make -C $(PRINTF_DIR) clean
	make -C $(LIBX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PRINTF_DIR) fclean
	make -C $(LIBX_DIR) clean
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
