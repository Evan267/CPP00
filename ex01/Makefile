SRCS	= main.cpp \
	  PhoneBook.cpp \
	  Contact.cpp

OBJS	= ${SRCS:.cpp=.o}

NAME	= PhoneBook

CC	= c++

FLAGS	= -Wall -Werror -Wextra -std=c++98

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS}
		${CC} ${FLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all fclean clean re
