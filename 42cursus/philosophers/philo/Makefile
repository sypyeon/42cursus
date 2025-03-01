CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = philo

M_SRC = 
M_OBJ = $(M_SRC:.c=.o)

B_SRC = 
B_OBJ = $(B_SRC:.c=.o)

OBJECTS =

ifdef BONUS
	OBJECTS += $(B_OBJ)
else
	OBJECTS += $(M_OBJ)
endif

all : $(NAME)

bonus:
	@$(MAKE) --no-print-directory BONUS=1 $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(M_OBJ) $(B_OBJ)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all clean fclean re bonus
