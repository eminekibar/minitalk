NAME_C = client
NAME_S = server

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC_C = client.c ft_printf.c ft_atoi.c
SRC_S = server.c ft_printf.c

all: $(NAME_C) $(NAME_S)

$(NAME_C):
	$(CC) $(FLAGS) $(SRC_C) -o $(NAME_C) 

$(NAME_S):
	$(CC) $(FLAGS) $(SRC_S) -o $(NAME_S)
 
clean:
	$(RM) server
	$(RM) client

fclean: 
	rm -rf $(NAME_C)
	rm -rf $(NAME_S)

re: fclean all

.PHONY: all clean fclean re
