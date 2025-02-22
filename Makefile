CFLAG= -Wall -Werror -Wextra
CC= cc
SRC= pipex.c tool.c split.c manager.c tools.c


all:
	$(CC) $(CFLAG) $(SRC) 