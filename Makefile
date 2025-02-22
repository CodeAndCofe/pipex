CFLAG= -Wall -Werror -Wextra
CC= cc
SRC= pipex.c tool.c split.c tools.c manager.c


all:
	$(CC) $(CFLAG) $(SRC) 