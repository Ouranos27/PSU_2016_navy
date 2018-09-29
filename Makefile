##
## Makefile for make file in /home/vhuylebr/Desktop/PSU_2016_my_sokoban
## 
## Made by valerian huylebroeck
## Login   <vhuylebr@epitech.net>
## 
## Started on  Sun Dec 11 15:57:32 2016 valerian huylebroeck
## Last update Sat Feb 18 13:39:27 2017 valerian huylebroeck
##

NAME = navy

CC = gcc

SRC = SRC/get_next_line.c SRC/main.c SRC/my_putnbr_base.c SRC/client.c\
	SRC/fight.c SRC/map.c SRC/vrf_error.c SRC/signal.c

OBJS = $(SRC:.c=.o)

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -Iinclude -L. -lft -L. -lmy

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: re clean fclean all
