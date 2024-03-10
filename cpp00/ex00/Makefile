NAME=megaphone

CC=c++

FLAGS= -Wall -Werror -Wextra  -std=c++98

SRC = megaphone.cpp

OBJS = ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${SRC} 

clean: 
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}
