CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -g
FUNCTIONS = src/*.c
FOLDER = obj
A_FILE = minilibmx.a
NAME = way_home
OBJECTS = obj/*.o

all: $(NAME) clean
$(NAME):
	@$(CC) $(CFLAGS) $(FUNCTIONS) -o $@ -I inc
clean:
	rm -rf src/*.h
uninstall: clean
	rm -rf $(NAME)
reinstall: uninstall all
