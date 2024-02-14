NAME = push_swap

FLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
ACTION_DIR = actions

SRC = sort.c  error_handling.c  build_stack.c ft_split.c parsing0.c parsing1.c toolbox0.c toolbox1.c toolbox2.c toolbox3.c pa_pb.c ra_rb_rr.c rra_rrb_rrr.c sa_sb_ss.c push_swap.c
 
SRC_OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(SRC_OBJ)

$(SRC_OBJ): %.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(SRC_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
