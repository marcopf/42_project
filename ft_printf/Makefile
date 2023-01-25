NAME	= libftprintf.a
HEADER	= ${NAME:.a=.h}
SRCS	= ft_printf.c ft_hex.c ft_writeptr.c printf_utils.c ft_itoa.c ft_strdup.c ft_calloc.c ft_bzero.c ft_putstr.c ft_strlen.c
OBJS	= ${SRCS:.c=.o}
BOBJS	= ${BSRCS:.c=.o}
FLAGS	= -Wall -Werror -Wextra
OPTIONS	= -c
CC		= gcc ${FLAGS}
RM		= rm -f

.o:.c
	${CC} ${OBJS} $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
