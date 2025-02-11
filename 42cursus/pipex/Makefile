CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = pipex
SOURCES = px_main.c \
	px_cmd_utils.c \
	px_path_utils.c \
	px_ft_free.c \
	px_heredoc_bonus.c

OBJECTS = $(SOURCES:.c=.o)

B_SRC = px_heredoc_bonus.c
B_OBJ = $(B_SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./libft

all : $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(OBJECTS) -o $(NAME) $(LIBFT)

bonus : $(B_OBJ) $(LIBFT)
	$(CC) $(B_OBJ) -o $(NAME) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C $(LIBFT_DIR)

clean :
	rm -f $(OBJECTS) $(B_OBJ)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all clean fclean re
