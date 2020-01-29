NAME	=	exercice04

SRC		=	src/

CNT		=	main.c	\
				\

OBJ		=	$(CNT:.c=.o)

FLAGS	=	-Wall	\
			-Werror	\
#			-ansi	\

HEADER	=	../includes/

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	gcc $(FLAGS) $^ -o $(NAME) -I $(HEADER)

%.o		:	%.c
	gcc $(FLAGS) -o $@ -c $^ -I $(HEADER)

clean	:
	/bin/rm -rf $(OBJ)

bclean	:
	/bin/rm -rf $(NAME)

fclean	:	clean bclean

re		:	fclean all
