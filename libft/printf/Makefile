NAME = libftprintf.a

COMPFLAG = cc -Wall -Werror -Wextra

SRC = ft_printf.c ft_printchar.c ft_printhex.c ft_printnbr.c \
	ft_printpointer.c ft_printstring.c ft_printunsigned.c

BONUS =

OBJ = $(SRC:.c=.o)

BONUSOBJ = $(BONUS:.c=.o)

all: $(NAME)

$(OBJ): $(SRC)
		$(COMPFLAG) -c $(SRC)

$(NAME): $(OBJ)
		ar -rc $(NAME) $(OBJ)

bonus: $(BONUSOBJ) $(OBJ)
		ar -rc $(NAME) $(BONUSOBJ) $(OBJ)

clean:
		rm -rf $(OBJ) $(BONUSOBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
