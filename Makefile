FLAGS=-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -D BUFFER_SIZE=1
NAME=so_long
SRC=so_long.c\
get_next_line.c\
get_next_line_utils.c\
draw_map.c\
fuknorms.c\
fuknorms2.c\
fuknorms3.c\
OBJ=so_long.o\
get_next_line.o\
get_next_line_utils.o\
draw_map.o\
fuknorms.o\
fuknorms2.o\
fuknorms3.o\

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
