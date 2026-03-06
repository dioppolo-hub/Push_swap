NAME = push_swap

BONUS = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRC_COMMON = libft/ft_atoi.c libft/ft_strcmp.c libft/ft_calloc.c libft/ft_split.c libft/ft_lstadd_front.c libft/ft_lstlast.c libft/ft_strdup.c libft/ft_strlen.c \
libft/ft_substr.c libft/ft_listnew.c libft/ft_lstclear.c libft/ft_listaddback.c libft/ft_lstdelone.c libft/ft_lstsize.c parcing/add_stack.c \
parcing/free_error.c operations/swap.c operations/push.c operations/rotate.c operations/reverse_rotate.c sorting/indice_stack.c \
sorting/sort_tre.c sorting/sort_four.c sorting/sort_five.c sorting/sort_generico.c sorting/fuck_this_number.c sorting/find_pos.c \
sorting/push_index.c sorting/execute_rotations_back.c sorting/chunks.c

SRC_PUSH = main.c

SRC_CHECKER = checker.c

OBJ_COMMON = $(SRC_COMMON:.c=.o)

OBJ_PUSH = $(SRC_PUSH:.c=.o)

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

INCLUDES = -I.

all: $(NAME)

$(NAME): $(OBJ_COMMON) $(OBJ_PUSH)
	$(CC) $(CFLAGS) $(OBJ_COMMON) $(OBJ_PUSH) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ_COMMON) $(OBJ_CHECKER)
	$(CC) $(CFLAGS) $(OBJ_COMMON) $(OBJ_CHECKER) -o $(BONUS)

%.o: %.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ_COMMON) $(OBJ_PUSH) $(OBJ_CHECKER)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus