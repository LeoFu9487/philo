NAME = philo

CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=address -g3

CC = gcc

SRCS_FILE = main.c	utils.c	init.c	parse.c	routine.c

SRCS_PATH = srcs/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILE))

OBJS = $(SRCS:.c=.o)

#PUT HEADERS HERE
HEADER_FILE = philo.h

HEADER_PATH = includes/

HEADER = $(addprefix $(HEADER_PATH), $(HEADER_FILE))

all : $(NAME)
	echo "Compile OK"

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I $(HEADER_PATH)  $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER_PATH) -c $< -o $@

clean :
	rm -rf $(OBJS)
	echo "clean OK"

fclean :
	rm -rf $(OBJS) $(NAME)
	echo "fclean OK"

re : fclean all

.PHONY: all clean fclean re

#.SILENT :
