NAME=fixed
CC=g++
FLAGS= -Wall -Werror -Wextra -std=c++98

SRC= main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ=${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${FLAGS} -o ${NAME} ${SRC}

clean: 
	rm ${OBJ}

fclean: clean
	rm ${NAME}

re: fclean all
