# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 13:40:58 by ekern             #+#    #+#              #
#    Updated: 2022/07/14 12:55:27 by ekern            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO = philo
NAME = $(PHILO)

CC = gcc
CFLAGS = 

INCLUDES = srcs/philo.h

SRCS = \
	srcs/philo_main.c	\
	srcs/philo_utils.c	\
	srcs/states.c

OBJS = ${SRCS:c=o}

all : $(NAME)

$(PHILO) : $(OBJS)
	$(CC) -pthread $(CFLAGS) $^ -o $(NAME)

srcs/%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re 