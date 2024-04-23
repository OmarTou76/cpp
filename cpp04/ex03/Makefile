NAME=exec

CC=c++

CFLAGS= -Wall -Werror -Wextra -std=c++98

SRC= main.cpp AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp

OBJS=${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${SRC} -g

clean: 
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

re: fclean all
