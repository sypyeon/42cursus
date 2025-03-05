CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = philo

M_SRC = philo_main.c	ph_atoi.c	philo_time.c\
	philo_init.c		philo_observer.c\
	philo_action.c		philo_mutex_manage.c
M_OBJ = $(M_SRC:.c=.o)

all : $(NAME)

$(NAME): $(M_OBJ)
	$(CC) $(CFLAGS) $(M_OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(M_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
