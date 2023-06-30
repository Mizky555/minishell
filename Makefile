NAME = minishell

DIR = srcs

INCLUDES = -I $(DIR)/vendors -I $(DIR)/models

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address $(INCLUDES)

SRCS = $(shell find srcs -name "*.c")

OBJS = $(SRCS:.c=.o)

RM = rm -f


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lreadline
	@echo "\033[32m[✔] \033[0m\033[1;32mCompilation done !\033[0m"

clean:
	@$(RM) $(OBJS)
	@echo "\033[31m[✔] \033[0m\033[1;31mClean done !\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[31m[✔] \033[0m\033[1;31mFclean done !\033[0m"

re: fclean all

.PHONY: all clean fclean re