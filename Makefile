# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmckinno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 12:49:59 by rmckinno          #+#    #+#              #
#    Updated: 2020/01/29 02:27:51 by rmckinno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

C_FLAGS = -Wall -Wextra -Werror

INCLS := ft_bsq.h
INCLDIR = lib/
HEADERS = $(addprefix $(INCLDIR), $(INCLS))

SRCS := bsq.c mapper.c boxer.c ft_util.c
SRCDIR = src/
FILES = $(addprefix $(SRCDIR), $(SRCS))

OBJS = $(FILES:.c=.o)

TARGET := bsq

all:	$(TARGET)

$(TARGET): $(OBJS)
		$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
		rm -f $(FILES:.c=.o)

fclean: clean
		rm -f $(TARGET)

re:		fclean all
