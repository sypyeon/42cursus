NAME = UnecessaryViolence

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

OBJ_DIR = ./obj
SRC = HumanA.cpp HumanB.cpp main.cpp Weapon.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))


all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus