##
## Makefile for  in /home/tbesson/PSU_2016_my_sokoban/bootstrap
## 
## Made by Tamsi Besson
## Login   <tbesson@epitech.net>
## 
## Started on  Tue Dec  6 14:57:19 2016 Tamsi Besson
## Last update Tue Feb 14 13:45:11 2017 Tamsi Besson
##

SRC=   	 	main.c \
		player.c \
		lib/my_getnbr.c \
		lib/my_put_nbr.c \
		lib/my_putnbr_base.c \
		lib/get_next_line.c \
		lib/my_str_to_wordtab.c \
		lib/my_strfct.c \

NAME	=	matchstick

OBJ=            $(SRC:.c=.o)

$(NAME):        $(OBJ)
		gcc -g -o $(NAME) $(OBJ)


all:            $(NAME)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re
