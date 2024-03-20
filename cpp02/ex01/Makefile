NAME=fixed

CC=g++

CFLAGS=-Wall -Werror -Wextra -std=c++98

SRC= main.cpp Fixed.cpp

OBJ= ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} -o ${NAME} ${SRC}

clean: 
	rm ${OBJ}

fclean: clean
	rm ${NAME}

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all
