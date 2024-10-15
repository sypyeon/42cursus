CC = cc

CFLAG = -Wall -Werror -Wextra

NAME = ft_printf.a

SOURCES = 

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