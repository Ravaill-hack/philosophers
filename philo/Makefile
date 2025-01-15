NAME = PHILO
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

SRC_FILES = \
	main.c \
	actions.c \
	lst_utils.c \
	utils.c \
	debug.c \
	end.c \
	init.c

OBJS = $(SRC_FILES:/%.c=/%.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re