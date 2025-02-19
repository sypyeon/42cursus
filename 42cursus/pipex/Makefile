CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = pipex
M_SRC = px_main.c \
	px_cmd_utils.c \
	px_path_utils.c \
	px_ft_free.c

M_OBJ = $(M_SRC:.c=.o)

B_SRC = px_main_bonus.c \
	px_cmd_utils_bonus.c \
	px_path_utils_bonus.c \
	px_ft_free_bonus.c \
	px_heredoc_bonus.c
B_OBJ = $(B_SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./libft

OBJECTS =

ifdef BONUS
	OBJECTS += $(B_OBJ)
else
	OBJECTS += $(M_OBJ)
endif

all : $(NAME)

bonus:
	@$(MAKE) --no-print-directory BONUS=1 $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C $(LIBFT_DIR)

clean :
	rm -f $(M_OBJ) $(B_OBJ)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all clean fclean re bonus
