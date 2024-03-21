NAME=unknown

CC=c++

CFLAGS= -Wall -Werror -Wextra -std=c++98

SRC= main.cpp  Dog.cpp Cat.cpp AAnimal.cpp Brain.cpp WrongCat.cpp WrongAnimal.cpp

OBJS= ${SRC:.cpp=.o}

all: ${NAME}


${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${SRC} 

%.cpp: %.o
	${CC} ${FLAGS} <$

clean: 
	rm ${OBJS}

fclean: clean
	rm ${NAME} ${CFLAGS} -c $< -o $@

re: fclean all


