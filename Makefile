CFLAG= -Wall -Werror -Wextra
CC= cc
SRC= pipex.c tool.c split.c tools.c manager.c
OBJ= $(SRC:.c=.o)
NAME= pipex

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAG) -c $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all