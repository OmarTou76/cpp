NAME=FragTrap

CC=g++

CFLAGS=-Wall -Werror -Wextra -std=c++98

SRC= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJ= ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} -o ${NAME} ${SRC}

clean: 
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all
