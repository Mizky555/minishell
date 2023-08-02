NAME = minishell

DIR = srcs

INCLUDES = -Iincludes

CC = cc #-g -fsanitize=address

CFLAGS = -Wall -Wextra -Werror   $(INCLUDES)

SRCS = \
srcs/main.c \
srcs/main2.c \
srcs/opal/built-in/export.c \
srcs/opal/built-in/env.c \
srcs/opal/built-in/pwd.c \
srcs/opal/built-in/cd.c \
srcs/opal/built-in/echo.c \
srcs/opal/built-in/exit.c \
srcs/opal/built-in/unset.c \
srcs/opal/built-in/export2.c \
srcs/opal/lexers/lexer.c \
srcs/opal/lexers/utils.c \
srcs/opal/lexers/space_spliter.c \
srcs/opal/lexers/redirect_spliter2.c \
srcs/opal/lexers/redirect_spliter.c \
srcs/earth/parser/parser.c \
srcs/earth/expander/expander.c \
srcs/earth/expander/expand_env.c \
srcs/earth/expander/expander2.c \
srcs/earth/expander/get_env.c \
srcs/earth/expander/expand_tilde.c \
srcs/earth/executor/pathname.c \
srcs/earth/executor/pipe_init.c \
srcs/earth/executor/process.c \
srcs/earth/executor/file_utils.c \
srcs/earth/executor/error_utils.c \
srcs/earth/executor/pipe_builder.c \
srcs/earth/executor/start_executor.c \
srcs/earth/executor/here_doc.c \
srcs/earth/executor/pipe_excutor.c \
srcs/earth/lexer/qoute_remover.c \
srcs/utils/nta.c \
srcs/utils/token.c \
srcs/utils/ft_strjoin_free.c \
srcs/utils/token2.c \
srcs/utils/ft_isspace.c \
srcs/utils/str_array2.c \
srcs/tools/get_next_line.c \
srcs/tools/libft/ft_lstiter.c \
srcs/tools/libft/ft_isalnum.c \
srcs/tools/libft/ft_strchr.c \
srcs/tools/libft/ft_strdup.c \
srcs/tools/libft/ft_putendl_fd.c \
srcs/tools/libft/ft_strlcat.c \
srcs/tools/libft/ft_isascii.c \
srcs/tools/libft/ft_atoi.c \
srcs/tools/libft/ft_lstadd_back.c \
srcs/tools/libft/ft_strtrim.c \
srcs/tools/libft/ft_split.c \
srcs/tools/libft/ft_tolower.c \
srcs/tools/libft/ft_lstadd_front.c \
srcs/tools/libft/ft_substr.c \
srcs/tools/libft/ft_lstnew.c \
srcs/tools/libft/ft_memmove.c \
srcs/tools/libft/ft_strlcpy.c \
srcs/tools/libft/ft_strrchr.c \
srcs/tools/libft/ft_bzero.c \
srcs/tools/libft/ft_strjoin.c \
srcs/tools/libft/ft_memset.c \
srcs/tools/libft/ft_striteri.c \
srcs/tools/libft/ft_lstsize.c \
srcs/tools/libft/ft_strlen.c \
srcs/tools/libft/ft_lstmap.c \
srcs/tools/libft/ft_putstr_fd.c \
srcs/tools/libft/ft_memcpy.c \
srcs/tools/libft/ft_memcmp.c \
srcs/tools/libft/ft_strnstr.c \
srcs/tools/libft/ft_toupper.c \
srcs/tools/libft/ft_memchr.c \
srcs/tools/libft/ft_itoa.c \
srcs/tools/libft/ft_strncmp.c \
srcs/tools/libft/ft_lstclear.c \
srcs/tools/libft/ft_isprint.c \
srcs/tools/libft/ft_lstdelone.c \
srcs/tools/libft/ft_putchar_fd.c \
srcs/tools/libft/ft_isdigit.c \
srcs/tools/libft/ft_putnbr_fd.c \
srcs/tools/libft/ft_calloc.c \
srcs/tools/libft/ft_strmapi.c \
srcs/tools/libft/ft_lstlast.c \
srcs/tools/libft/ft_isalpha.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

READLINE_L += -L/usr/local/opt/readline/lib
CC += -I/usr/local/opt/readline/include

READLINE_L += -L/opt/homebrew/opt/readline/lib
CC += -I/opt/homebrew/opt/readline/include

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(READLINE_L) $(OBJS) -lreadline
	@echo "\033[32m[✔] \033[0m\033[1;32mCompilation done !\033[0m"

clean:
	@$(RM) $(OBJS)
	@echo "\033[31m[✔] \033[0m\033[1;31mClean done !\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[31m[✔] \033[0m\033[1;31mFclean done !\033[0m"

re: fclean all

norm-init:
	norminette

.PHONY: all clean fclean re
