LIB = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
	ft_memset.c ft_toupper.c ft_tolower.c ft_atoi.c ft_strlcpy.c ft_strlcat.c \
	ft_strdup.c ft_strncmp.c ft_bzero.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
	ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strtrim.c \
	ft_strjoin.c ft_substr.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstiter.c ft_lstmap.c

SRCS = ${LIB}

SRCS_ALL = ${LIB} ${BONUS}

OBJS = ${SRCS:.c=.o}

OBJS_ALL = ${SRCS_ALL:.c=.o}

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I ./

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar -rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS_ALL}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

bonus:	${OBJS_ALL}
	ar -rcs ${NAME} ${OBJS_ALL}

.PHONY: all clean fclean re bonus
