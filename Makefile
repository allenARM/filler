NAME = amelikia.filler
LIBFT = libft/libft.a
INCLUDES = -I includes
FLAGS = -Wall -Wextra -Werror
SRCS = ./srcs/*.c

all: $(NAME)

$(NAME):
#	make -C Libft
	gcc $(FLAGS) $(LIBFT) $(INCLUDES) filler.c -o $(NAME)

clean:
	/bin/rm -f $(OBJ)
#	make -C Libft clean

fclean: clean
	/bin/rm -f $(NAME)
#	make -C Libft fclean

deb:
	gcc -g -fsanitize=address $(FLAGS) $(LIBFT) $(INCLUDES) filler.c -o $(NAME)

re: fclean all
