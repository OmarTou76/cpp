NAME=Zombie

CC=c++

FLAGS= -Wall -Werror -Wextra  -std=c++98

SRC = main.cpp Zombie.cpp zombieHorde.cpp

OBJS = ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${SRC} 

clean: 
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re: fclean all
