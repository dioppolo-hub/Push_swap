NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs

SRC = ft_atoi.c ft_calloc.c ft_split.c ft_strdup.c ft_strlen.c ft_substr.c ft_listnew.c ft_lstaddback.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re