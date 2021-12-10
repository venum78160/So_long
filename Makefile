CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

NAME = so_long

SRC = main.c \
	affichage.c \
	deplacement.c \
	fonction_aff.c \
	fonction_utile.c \
	test_maps.c \
	map.c \
	affichage2.c

OBJ = $(SRC:.c=.o)

RM = rm -f

%.o : %.c
		$(CC) -o $@ -c $< $(CFLAGS)
$(NAME) 	:	$(OBJ)
		$(MAKE) -C ./libft
		cp libft/libft.a $(NAME)
		$(MAKE) -C ./gnl
		cp gnl/gnl.a $(NAME)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) gnl/gnl.a libft/libft.a

all : $(NAME)

clean :
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./gnl
		$(RM) $(OBJ)

fclean : clean
		$(MAKE) fclean -C ./libft
		$(MAKE) fclean -C ./gnl
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re