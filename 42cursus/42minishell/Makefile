CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
NAME		=	minishell
INCLUDES	=	-I./include -I./libft

OBJS_DIR	=	./obj
OBJS		=	$(SOURCES_OBJ)	\
				$(BUILTIN_OBJ)	\
				$(HASH_OBJ)		\
				$(PIPEX_OBJ)	\
				$(PARSE_OBJ)	\
				$(ENV_OBJ)		\
				$(SIGNAL_OBJ)	
# $(EXEC_OBJ)	\
# $(UTILS_OBJ)	\


SOURCES		= 	minishell.c
SOURCES_OBJ =	$(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))

PIPEX_DIR	=	./pipe
PIPEX_SRC	=	ms_pipe.c			ms_pipe_dup.c	ms_pipe_utils.c	\
				ms_pipe_heredoc.c	ms_heredoc_parse.c
PIPEX_OBJ	=	$(addprefix $(OBJS_DIR)/, $(PIPEX_SRC:.c=.o))

BUILTIN_DIR	=	./builtin
BUILTIN_SRC =	ms_builtin_cd.c	ms_builtin_pwd.c \
				ms_builtin_export.c ms_builtin_unset.c \
				ms_builtin_env.c ms_builtin_echo.c \
 				ms_builtin_exit.c ms_builtin_utils.c 
BUILTIN_OBJ	=	$(addprefix $(OBJS_DIR)/, $(BUILTIN_SRC:.c=.o))

ENV_DIR 	=	./env
ENV_SRC 	=	ms_env_tool.c
ENV_OBJ 	=	$(addprefix $(OBJS_DIR)/, $(ENV_SRC:.c=.o))

HASH_DIR	=	./hash
HASH_SRC	=	ms_hash_init.c	ms_hash_utils.c	ms_hash_free.c
HASH_OBJ	=	$(addprefix $(OBJS_DIR)/, $(HASH_SRC:.c=.o))

# UTILS_DIR	=	./utils
# UTILS_SRC	=	ms_utils.c	ms_utils_exit.c	ms_mem_free.c
# UTILS_OBJ	=	$(addprefix $(OBJS_DIR)/, $(UTILS_SRC:.c=.o))

# EXEC_DIR	=	./execute
# EXEC_SRC	=	ms_execute_logic.c	ms_close_fd.c	ms_execute_cmd.c	\
# 				ms_processing.c		ms_init_var.c	ms_script_loop.c	\
# 				ms_set_pipe.c		ms_handle_heredoc.c
# EXEC_OBJ	=	$(addprefix $(OBJS_DIR)/, $(EXEC_SRC:.c=.o))

PARSE_DIR	=	./parse
PARSE_SRC	=	ms_check_redirection.c	ms_cmd_info_init.c		\
				ms_env_replace.c		ms_handle_redirection.c	\
				ms_identify_char.c		ms_split.c				\
				ms_string_utils.c		ms_apply_redirection.c	\
				ms_free_function.c		ms_cmd_init_utils.c		\
				ms_run_input.c
PARSE_OBJ	=	$(addprefix $(OBJS_DIR)/, $(PARSE_SRC:.c=.o))

SIGNAL_DIR	=	./signal
SIGNAL_SRC	=	ms_signal_utils.c ms_heredoc_sinal_utils.c
SIGNAL_OBJ	=	$(addprefix $(OBJS_DIR)/, $(SIGNAL_SRC:.c=.o))

LIBFTDIR	=	./libft
LIBFT		=	$(LIBFTDIR)/libft.a

vpath %.c	$(BUILTIN_DIR) $(HASH_DIR) $(PIPEX_DIR) $(PARSE_DIR) $(ENV_DIR)\
			$(SIGNAL_DIR)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -lreadline

$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(LIBFTDIR) $(INCLUDES) -o $@ -c $<

$(LIBFT) :
	@make -C $(LIBFTDIR) all

clean :
	rm -f $(OBJS)
	@make -C $(LIBFTDIR) clean

fclean : clean
	rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re : fclean all

.PHONY : all clean fclean re
