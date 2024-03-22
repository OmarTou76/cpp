NAME=unknown

CC=c++

CFLAGS= -Wall -Werror -Wextra -std=c++98

SRC= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp WrongCat.cpp WrongAnimal.cpp

OBJS= ${SRC:.cpp=.o}

all: ${NAME}


${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${SRC} 

%.o: %.cpp
	${CC} ${FLAGS} -c $< -o $@

clean: 
	rm ${OBJS}

fclean: clean
	rm ${NAME}

re: fclean all


