CC = gcc

CFLAGS = -Wall -Wextra #-Werror

NAME = philo

SRCS = main.c ft_atoi.c ft_isdigit.c init.c life.c time.c

OBJS = $(SRCS:.o=.c)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
