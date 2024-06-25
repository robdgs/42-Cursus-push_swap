CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
SRCS = algo_utils.c comput_efficiency.c easy_sort.c error_handling.c \
		ft_push.c ft_rev_rotate.c ft_rotate.c ft_swap.c input_checks.c \
		main.c moves_exec.c parsing_utils.c parsing.c stack_init.c \
		stack_utils.c terror_sort.c where.c

all:	${NAME}

${NAME}: ${SRCS}
	${CC}	${CFLAGS}	${SRCS} -o ${NAME}	


clean:
	${RM}

fclean:	clean
	${RM}	${NAME}

re:	fclean	all

.PHONY:	all	clean	fclean	re


