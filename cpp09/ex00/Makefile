NAME=btc

CC=c++

CFLAGS= -Wall -Werror -Wextra -std=c++98

SRC= main.cpp BitcoinExchange.cpp 

H= BitcoinExchange.h

OBJS= ${SRC:.cpp=.o}

all: ${NAME}


${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${SRC} 

%.o: %.cpp ${H}
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all


