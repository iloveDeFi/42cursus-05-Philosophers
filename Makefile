# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bat <bat@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 10:07:23 by bat               #+#    #+#              #
#    Updated: 2023/07/11 09:24:42 by bat              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philo

SRCS 		= actions.c \
       errors_&_messages.c \
       free_&_finish.c \
       main_&_init.c \
	   simulation.c \
	   state.c \
	   time.c 

INCLUDES 	= philo.h \

OBJS 		= $(SRCS:.c=.o)

SRCS		= $(wildcard *.c)

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -g -fsanitize=thread -pthread

RM 			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
