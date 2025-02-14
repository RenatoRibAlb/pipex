NAME = pipex

LIBFT = libft/

LIBFT_A =	$(LIBFT)libft.a

COMPFLAG = cc -Wall -Werror -Wextra

SRC = pipex.c pipex_utils.c

BONUS =

OBJ = $(SRC:.c=.o)

BONUSOBJ = $(BONUS:.c=.o)

all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJ)
		$(COMPFLAG) $(OBJ) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
		make -C $(LIBFT)

bonus: $(BONUSOBJ) $(OBJ)
		ar -rc $(NAME) $(BONUSOBJ) $(OBJ)

clean:
		rm -rf $(OBJ) $(BONUSOBJ)

fclean: clean
		rm -rf $(OBJ) $(NAME)

re: fclean all
