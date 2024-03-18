NAME=FragTrap

CC=g++

FLAGS=-Wall -Werror -Wextra -std=c++98

SRC= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJ= ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${FLAGS} -o ${NAME} ${SRC}

clean: 
	rm ${OBJ}

fclean: clean
	rm ${NAME}

re: fclean all
