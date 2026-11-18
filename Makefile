CC      = gcc
CFLAGS  = -Wall -Werror -Wextra -pedantic -std=gnu89
SRCS    = 0-strcat.c 2-strlen.c 3-strcmp.c 3-strdup.c 9-strcpy.c \
          execute.c freecmd.c getenv.c getpath.c handl_builtin.c \
          main.c readline.c tokenizer.c touls.c
OBJS    = $(SRCS:.c=.o)
TARGET  = hsh

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
