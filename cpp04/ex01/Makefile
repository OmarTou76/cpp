NAME=exec

CC=c++

CFLAGS= -Wall -Werror -Wextra -std=c++98

SRC= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
H= Animal.hpp Dog.hpp Cat.hpp Brain.hpp
OBJS= ${SRC:.cpp=.o}

all: ${NAME}


${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${SRC} 

%.o: %.cpp
	${CC} ${FLAGS} -c $< -o $@

clean: 
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all
