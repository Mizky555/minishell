NAME = minishell

DIR = srcs

INCLUDES = -Iincludes

CC = cc -g -fsanitize=address

CFLAGS = -Wall -Wextra -Werror   $(INCLUDES)

SRCS = $(shell find srcs -name "*.c")

OBJS = $(SRCS:.c=.o)

RM = rm -f

UNAME = $$(uname)
READLINE_L += -L/usr/local/opt/readline/lib
CC += -I/usr/local/opt/readline/include

READLINE_L += -L/opt/homebrew/opt/readline/lib
CC += -I/opt/homebrew/opt/readline/include

test:
	@echo $(UNAME)
	@echo $$(uname)
	@echo ${READLINE_L}
	@echo ${CC}

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
	source .venv/bin/activate
	norminette

.PHONY: all clean fclean re
