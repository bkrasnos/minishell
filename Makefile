SRCS	=	main.c \
			./env/ft_environs.c \
			./env/ft_sort_env.c \
			./parsing/parser.c \
			./parsing/pre_parser.c \
			./parsing/init_cmds.c \
			./parsing/redir.c \
			./parsing/parse_line.c \
			./lexer/tokens.c \
			./executer/ft_executer.c \
			./executer/ft_executer_utils.c \
			./executer/process.c \
			./executer/builtins/builtins.c \
			./executer/builtins/ft_cd.c \
			./executer/builtins/ft_echo.c \
			./executer/builtins/ft_env.c \
			./executer/builtins/ft_exit.c \
			./executer/builtins/ft_export.c \
			./executer/builtins/ft_pwd.c \
			./executer/builtins/ft_unset.c \
			./libft/ft_atoi.c \
			./libft/ft_lstiter.c \
			./libft/ft_putstr_fd.c \
			./libft/ft_strnstr.c \
			./libft/ft_strchr.c \
			./libft/ft_strlen.c \
			./libft/ft_putendl_fd.c \
			./libft/ft_putchar_fd.c \
			./libft/ft_strncmp.c \
			./libft/ft_isalnum.c \
			./libft/ft_isdigit.c \
			./libft/ft_strjoin.c \
			./libft/ft_split.c \
			./libft/ft_strdup.c \
			./libft/ft_calloc.c \
			./libft/ft_substr.c \
			./libft/ft_memcpy.c \
			./libft/ft_isalpha.c \
			./libft/ft_memset.c \
			./libft/ft_lstnew.c \
			./libft/ft_strtrim.c \
			./libft/ft_lstadd_back.c \
			./libft/ft_lstclear.c \
			./libft/ft_lstsize.c \
			./libft/ft_lstdelone.c \
			./libft/ft_strlcpy.c \
			./libft/ft_putnbr_fd.c \
			ft_free.c \
			ft_signal.c \
			error.c

NAME := minishell
CC := gcc
CFLAGS := -Werror -Wall -Wextra -g
RDL_PATH := -L/Users/$(USER)/.brew/opt/readline/lib/
RDL_HISTORY_PATH := -L/Users/$(USER)/.brew/opt/readline/lib/
RDL := -lreadline.8.1 $(RDL_PATH)
RDL_HISTORY := -lhistory.8.1 $(RDL_HISTORY_PATH)
READLINE := $(RDL) $(RDL_HISTORY)
HEADER	= minishell.h
RM := rm -rf
OBJ_FILES := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
		@$(CC) $(CFLAGS) $(OBJ_FILES) $(READLINE) -o $(NAME)
		@echo "Minishell compiled"
		@echo "Simply type ./minishell to execute the program. Enjoy."

clean:
	@rm -f $(OBJ_FILES)
	@echo "All <file>.o are removed."

fclean: clean
	@rm -f $(NAME)
	@echo "./minishell is removed."

re: fclean all

.PHONY:	clean fclean re
