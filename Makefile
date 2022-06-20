FLAGS=-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
NAME=so_long
SRC=draw_map.c\
	fuknorms2.c\
	get_next_line.c\
	so_long.c\
	fuknorms.c\
	fuknorms3.c\
	get_next_line_utils.c\

OBJ=draw_map.o\
	fuknorms2.o\
	get_next_line.o\
	so_long.o\
	fuknorms.o\
	fuknorms3.o\
	get_next_line_utils.o\

all:$(NAME)

$(NAME):$(OBJ)
	cc $(FLAGS) -o $@ $(OBJ)

$(OBJ) : $(SRC)
	cc -c $(SRC)

clean:
	rm -rf $(OBJ)
	echo "CLEANED"

re: clean all
fclean: clean
	rm -rf $(OBJ)
	rm -rf $(NAME)
