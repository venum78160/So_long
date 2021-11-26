CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

NAME = so_long

SRC = main.c

OBJ = $(SRC:.c=.o)

RM = rm -f

%.o : %.c
		$(CC) -o $@ -c $< $(CFLAGS)
$(NAME) 	:	$(OBJ)
		$(MAKE) -C ./libft
		cp libft/libft.a $(NAME)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX)

all : $(NAME)

clean :
		$(MAKE) clean -C ./libft
		$(RM) $(OBJ)

fclean : clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re