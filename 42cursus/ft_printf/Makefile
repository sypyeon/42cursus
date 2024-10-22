CC = cc

CFLAG = -Wall -Werror -Wextra

NAME = ft_printf.a

SOURCES = ft_printf.c \
		ft_d.c \
		ft_s.c \
		ft_u.c \
		ft_x.c \
		ft_xupper.c \
		ft_p.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strlen.c

OBJECTS = $(SOURCES:.c=.o)

.PHONY = $(NAME) all clean fclean re

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $@ $<

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all