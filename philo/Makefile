NAME = PHILO
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = \
	main.c \
	utils.c

OBJS = $(SRC_FILES:/%.c=/%.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CC)$(CFLAGS)$(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re