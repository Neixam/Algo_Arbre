NAME =	Compte

SRC = src/

CNT	=	$(SRC)ex01.c\
		$(SRC)ex02.c\
		$(SRC)ex03.c\
		$(SRC)ex04.c\
		$(SRC)ex05.c\
		$(SRC)ex06.c\
		$(SRC)ex07.c\
		$(SRC)ex09.c\
		$(SRC)main.c\
		

OBJ = $(CNT:.c=.o)

FLAGS = -Wall	\
		-ansi	\
		-Werror	\

HEADER	= includes

all:$(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $^ -o $(NAME) -I $(HEADER)

%.o:%.c
	gcc $(FLAGS) -o $@ -c $^ -I $(HEADER)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
