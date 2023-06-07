NAME	= violence
HEADER	= ${NAME:.a=.h}
SRCS	=	$(wildcard *.cpp)
OBJS	= ${SRCS:.cpp=.o}
BOBJS	= ${BSRCS:.cpp=.o}
FLAGS	= -Wall -Werror -Wextra
OPTIONS	= -c
CC		= g++
RM		= rm -f

.o:.cpp
	$(CC) $(FLAGS) -std=c++98 -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) $(OBJS) $(FLAGS) -std=c++98 -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re libft