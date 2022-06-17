#ifndef SO_LONG_H
# define SO_LONG_H
#include "get_next_line.h"
#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct elements{
    int E;
    int C;
    int P;
};

typedef struct p{
    void *ptr;
    void *w_ptr;
    void *player;
    void *backg;
}ptr;
int     ft_count_lines(char *name);
#endif