CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -g -std=c++98

NAME = phonebook

OBJ_DIR = ./obj
SRC = main.cpp Contact.cpp PhoneBook.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus