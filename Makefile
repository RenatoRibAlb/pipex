NAME = pipex.a

LIBFT = libft/

LIBFT_A =	$(LIBFT)libft.a

COMPFLAG = cc -Wall -Werror -Wextra

SRC =

BONUS =

OBJ = $(SRC:.c=.o)

BONUSOBJ = $(BONUS:.c=.o)

all: $(LIBFT_A) $(NAME)

$(OBJ): $(SRC)
		$(COMPFLAG) -c $(SRC)

$(NAME): $(OBJ)
		ar -rc $(NAME) $(OBJ)

$(LIBFT_A):
		make -C $(LIBFT)

bonus: $(BONUSOBJ) $(OBJ)
		ar -rc $(NAME) $(BONUSOBJ) $(OBJ)

clean:
		rm -rf $(OBJ) $(BONUSOBJ)

fclean: clean
		rm -rf $(OBJ) $(NAME)

re: fclean all
