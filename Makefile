FLAGS=-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
NAME=so_long
SRC=get_next_line.c\
get_next_line_utils.c\
draw_map.c\
fuknorms.c\
fuknorms2.c\
fuknorms3.c\
so_long.c\

OBJ=$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	cc $(FLAGS) -o $@ $(OBJ)

$(OBJ) : $(SRC)
	cc $(FLAGS) -c $(SRC)

clean:
	rm -rf $(OBJ) $(OBJ_B)
	echo "CLEANED"

re: clean all
fclean: clean
	rm -rf $(NAME)
