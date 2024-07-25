NAME = bin/text-editor

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c srcs/ft_string.c srcs/ft_file.c

OBJS_DIR = objs
BIN_DIR = bin
OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
