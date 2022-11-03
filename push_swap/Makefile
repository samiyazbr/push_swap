CC = gcc
CFLAGS = -Werror -Wextra -Wall
SRC = ./src/check.c ./src/free.c ./src/get_value_utils.c ./src/push_command.c ./src/push_swap_utils.c ./src/push_swap.c ./src/push.c ./src/reverse_rotate_cmd.c ./src/rotate_command.c ./src/sorting.c ./src/swap_command.c

SRC_BONUS = ./bonus/checker_utils.c ./bonus/checker_utils2.c ./bonus/checker.c ./bonus/instructions_checker_2.c ./bonus/instructions_checker_3.c ./bonus/instructions_checker.c ./gnl/get_next_line.c \
			./gnl/get_next_line_utils.c


OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME = push_swap
NAME_BONUS = checker

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)


bonus: $(NAME_BONUS) $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJ_BONUS) -Llibft -lft -o $(NAME_BONUS)

clean:
	@make -C ./libft clean
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@echo "Objects Removed !"
	
fclean: clean
	@make -C ./libft fclean
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "Binary Removed !"

re: fclean all