CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = push_swap
SOURCES = main.c \
	ft_init_stack.c \
	ft_push.c \
	ft_swap.c \
	ft_rotate.c \
	ft_rev_rotate.c \
	ps_check_error.c \
	ps_free.c \
	ps_sort.c \
	ps_split_av.c
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

.PHONY : all clean fclean re
