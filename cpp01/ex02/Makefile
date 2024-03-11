NAME=prog

SRC=main.cpp

CC=g++

FLAGS= -Wall -Werror -Wextra -std=c++98

OBJ=${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${FLAGS} -o ${NAME} ${SRC}

clean: 
	rm ${OBJ}

fclean: clean
	rm ${NAME}
