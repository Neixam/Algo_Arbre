NAME	=	tp3

SRC		=	src/

CNT		=	$(SRC)main.c		\
			$(SRC)affiche_err.c	\
			$(SRC)donnee_s.c	\
			$(SRC)ex01.c		\
			$(SRC)ex02.c		\
			$(SRC)ex03.c		\
			$(SRC)ex04.c		\
			$(SRC)ex05.c		\

HEADER	=	includes/

FLAGS 	=	-Wall		\
			-ansi		\
			-pedantic	\

OBJ		=	$(CNT:.c=.o)

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
