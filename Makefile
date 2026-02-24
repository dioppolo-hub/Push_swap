NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRC = libft/ft_atoi.c libft/ft_calloc.c libft/ft_split.c libft/ft_lstadd_front.c libft/ft_lstlast.c libft/ft_strdup.c libft/ft_strlen.c \
libft/ft_substr.c libft/ft_listnew.c libft/ft_listaddback.c libft/ft_lstdelone.c libft/ft_lstsize.c parcing/add_stack.c \
parcing/free_error.c operations/swap.c operations/push.c operations/rotate.c operations/reverse_rotate.c sorting/indice_stack.c \
 sorting/sort_tre.c sorting/sort_four.c sorting/sort_five.c sorting/sort_generico.c main.c

OBJ = $(SRC:.c=.o)

INCLUDES = -I.

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re