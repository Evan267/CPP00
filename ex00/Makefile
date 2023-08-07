SRCS	= megaphone.cpp

OBJS	= ${SRCS:.cpp=.o}

NAME	= megaphone

CC	= c++

FLAGS	= -Wall -Werror -Wextra -std=c++98

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		${CC} ${FLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all fclean clean re
