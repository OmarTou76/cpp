NAME=phonebook

CC=c++

FLAGS= -Wall -Werror -Wextra  -std=c++98

SRC = main.cpp phonebook.cpp contact.cpp

OBJS = ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${SRC} 

clean: 
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}
