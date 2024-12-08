CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

LIBFT = $(LIBFT_DIR)/libft.a

LIBFT_DIR = ./libft

SOURCES = push_swap.c\
	sorting_fuction.c

OBJECTS = $(SOURCES:.c=.o)

.PHONY : $(NAME) all clean fclean re

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT)
	make -C $(LIBFT_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

