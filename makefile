NAME = t_ordered_list

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c t_ordered_list.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c t_ordered_list.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re run valgrind