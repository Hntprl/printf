NAME = libftprintf.a
CC = CC
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

CRS = ft_additionalfuncs.c ft_printf.c ft_convertprints.c\

OCRS = $(CRS:.c=.o)

all: $(NAME)

clean:
	$(RM) $(CRS:.c=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(NAME): $(CRS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@