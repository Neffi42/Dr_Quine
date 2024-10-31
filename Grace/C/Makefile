NAME	= Grace
SRC_DIR	= src
OBJ_DIR = obj
SRC     = Grace.c
OBJ     = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
CC      = cc
CFLAGS  = -Wall -Werror -Wextra -g3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) Grace_kid.c

re: fclean all

.PHONY: all clean fclean re test
