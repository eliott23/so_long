FLAGS=-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -D BUFFER_SIZE=1
NAME=so_long
SRC=so_long.c\
	get_next_line.c\
	get_next_line_utils.c\
	draw_map.c\
	fuknorms.c\
	fuknorms2.c\
	fuknorms3.c\

all:$(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) -o $(NAME) $(SRC)

$(OBJ) : $(SRC)
	cc $(FLAGS) -c $(SRC)

clean:
	rm -rf *.o so_long
	echo "CLEANED"

re: clean all
fclean: clean
	rm -rf $(NAME)
