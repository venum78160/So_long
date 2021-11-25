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
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX)
all : $(NAME)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re