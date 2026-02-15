NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = libft/ft_atoi.c libft/ft_calloc.c libft/ft_split.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_substr.c \
libft/ft_listnew.c libft/ft_listaddback.c parcing/add_stack.c parcing/free.c main.c

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