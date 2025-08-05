NAME = BraiiiiiiinnnzzzZ

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

OBJ_DIR = ./obj
SRC = main.cpp newZombie.cpp  randomChump.cpp  Zombie.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))


all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus