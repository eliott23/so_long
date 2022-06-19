FLAGS=-Wall -Wextra -Werror
NAME=push_swap
B_NAME=checker
SRC=ft_atoi.c\
indexing.c\
instructions.c\
instructions_2.c\
low_tools.c\
optimization.c\
protect_tools.c\
s_indexing.c\
sort_five.c\
push_swap.c\

SRC_B =bonus/b_low_tools.c\
bonus/b_instructions.c\
bonus/b_ins2.c\
bonus/checker.c\
bonus/get_next_line.c\
bonus/get_next_line_utils.c\
bonus/b_atoi.c\
bonus/b_protect.c\
bonus/fnorms.c\

OBJ=$(SRC:.c=.o)
OBJ_B=b_low_tools.o\
b_instructions.o\
b_ins2.o\
checker.o\
get_next_line.o\
get_next_line_utils.o\
b_atoi.o\
b_protect.o\
fnorms.o

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
	rm -rf $(B_NAME)

bonus: $(B_NAME)

$(B_NAME) : $(OBJ_B)
	cc $(FLAGS) -o $@ $(OBJ_B)

$(OBJ_B) : $(SRC_B)
	cc $(FLAGS) -c $(SRC_B) -D BUFFER_SIZE=3
