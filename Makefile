# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouzalm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 08:40:18 by tbouzalm          #+#    #+#              #
#    Updated: 2022/03/12 10:15:03 by tbouzalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client

NAME2 = server

NAME1_bonus = client_bonus

NAME2_bonus = server_bonus

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC1 =  client.c minitalk_utils.c

SRC2 =  server.c minitalk_utils.c

SRC1_BONUS = client_bonus.c minitalk_utils_bonus.c

SRC2_BONUS = server_bonus.c minitalk_utils_bonus.c

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

OBJ1_bonus = $(SRC1_BONUS:.c=.o)

OBJ2_bonus = $(SRC2_BONUS:.c=.o)

%.o: %.c minitalk.h minitalk_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME1) $(NAME2) $(NAME1_bonus) $(NAME2_bonus)

$(NAME1): $(OBJ1) 
	$(CC) $(FLAGS) -o $@ $^

$(NAME2): $(OBJ2)
	$(CC) $(FLAGS) -o $@ $^

$(NAME1_bonus): $(OBJ1_bonus)
	$(CC) $(FLAGS) -o $@ $^

$(NAME2_bonus): $(OBJ2_bonus)
	$(CC) $(FLAGS) -o $@ $^

clean:
	$(RM) $(OBJ1) $(OBJ2) $(OBJ1_bonus) $(OBJ2_bonus)

fclean: clean
	$(RM) $(NAME1) $(NAME2) $(NAME1_bonus) $(NAME2_bonus)

re: fclean all
