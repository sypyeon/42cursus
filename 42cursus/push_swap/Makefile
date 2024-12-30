CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
NAME = push_swap
SOURCES = main.c \
	stack_function_check.c\
	ft_init_stack.c \
	ft_push.c \
	ft_swap.c \
	ft_rotate.c \
	ft_rev_rotate.c \
	ps_radix_sort.c \
	ft_free.c
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
