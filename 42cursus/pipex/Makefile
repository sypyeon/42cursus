CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = pipex
SOURCES = pipex.c \
OBJECTS = $(SOURCES:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./libft

all : $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(OBJECTS) -o $(NAME) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C $(LIBFT_DIR)

clean :
	rm -f $(OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all clean fclean re
