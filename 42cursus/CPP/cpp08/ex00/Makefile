CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

NAME := easyfind
SRC := main.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

