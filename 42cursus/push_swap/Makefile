CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
SOURCES = push_swap.c\
	sorting_fuction.c
OBJECTS = $(SOURCES:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./libft

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c  $<

$(LIBFT) :
	make -C $(LIBFT_DIR)

clean :
	rm -f $(OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : $(NAME) all clean fclean re
