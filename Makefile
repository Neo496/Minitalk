# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atouba <atouba@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 15:00:58 by atouba            #+#    #+#              #
#    Updated: 2022/03/23 15:33:20 by atouba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME_A = client

CC = cc

all: $(NAME) $(NAME_A)

# FILES = server.c client.c

# OBJS=$(FILES:.c=.o)

$(NAME):
	$(CC) server.c -o server

$(NAME_A):
	$(CC) client.c -o client

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME) $(NAME_A)

re:	fclean all