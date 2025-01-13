CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = so_long
SOURCES = test.c

OBJECTS = $(SOURCES:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./libft

MLX = $(MLX_DIR)/libmlx.a
MLX_DIR = ./mlx

all : $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX)
	$(CC) $(OBJECTS) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(MLX) :
	make -C $(MLX_DIR)

clean :
	rm -f $(OBJECTS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

re : fclean all

.PHONY : all clean fclean re
