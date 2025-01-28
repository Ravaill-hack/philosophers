NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

SRC_FILES = \
	main.c \
	actions.c \
	utils.c \
	manage.c \
	error.c \
	check.c \
	routines.c \
	init.c

OBJS = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re