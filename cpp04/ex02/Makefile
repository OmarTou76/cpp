NAME=exec

CC=c++

CFLAGS= -Wall -Werror -Wextra -std=c++98

SRC= main.cpp  Dog.cpp Cat.cpp AAnimal.cpp Brain.cpp
H= Dog.hpp Cat.hpp AAnimal.hpp Brain.hpp

OBJS= ${SRC:.cpp=.o}

all: ${NAME}


${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${SRC} 

%.o: %.cpp ${H}
	${CC} ${FLAGS} -c $< -o $@

clean: 
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all


