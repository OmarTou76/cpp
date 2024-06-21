NAME=exec

CC=c++

CFLAGS= -Wall -Werror -Wextra -std=c++98

SHRUBBERY_FILES=*_shrubbery

SRC= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

H= Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

OBJS= ${SRC:.cpp=.o}

all: ${NAME}


${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${SRC} 

%.o: %.cpp ${H}
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	rm -rf ${OBJS} 

fclean: clean
	rm -rf ${NAME} ${SHRUBBERY_FILES}

re: fclean all


