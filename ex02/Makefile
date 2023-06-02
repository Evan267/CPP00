SRCS	= tests.cpp \
	  Account.cpp

OBJS	= ${SRCS:.cpp=.o}

HEAD	= Account.hpp

NAME	= Account

CC	= c++

FLAGS	= -Wall -Werror -Wextra -std=c++98

.c.o:
		${CC} ${FLAGS} -I${HEAD} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS}
		${CC} ${FLAGS} -I${HEAD} ${OBJS} -o ${NAME}

all:		${NAME}

clean:		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all fclean clean re
