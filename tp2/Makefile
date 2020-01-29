NAME	=	tp2

SRC	    =	src/

EXTRA	=	ex04/

CNT	    =	$(SRC)main.c	\
		    $(SRC)ex01.c	\
		    $(SRC)ex02.c	\
		    $(SRC)ex03.c	\

OBJ    	=	$(CNT:.c=.o)

FLAGS	=	-Wall	\
		    -Werror	\
		    -ansi	\

HEADER	=	includes/

all 	:	$(NAME)

$(NAME)	:	$(OBJ)
	gcc $(FLAGS) $^ -o $(NAME) -I $(HEADER)
	make -C $(EXTRA)

%.o	    :	%.c
	gcc $(FLAGS) -o $@ -c $^ -I $(HEADER)

clean	:
	/bin/rm -rf $(OBJ)
	make -C $(EXTRA) clean

bclean	:
	/bin/rm -rf $(NAME)
	make -C $(EXTRA) bclean

fclean	:	clean bclean

re	    :	fclean all
