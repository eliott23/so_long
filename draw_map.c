#include "so_long.h"

int valid_move(char **map, int x, int y, ptr *l)
{
    if (map[y][x] != '1' && map[y][x] != 'E')
    {
        if (map[y][x] == 'C')
        {
            map[y][x] = '0';
            l->n_coin--;
        }
        return (1);
    }
    if (map[y][x] == 'E' && !l->n_coin)
    {
        lgebs(0,0,0, 3, 0);
        exit(0);
    }
    return (0);
}

void    double_free(char **str, int y)
{
    while (y--)
        free(str[y + 1]);
    free(str[0]);
    free(str);
}

void    str_map(char *name, ptr *l)
{
    int     y;
    int     i;
    int     fd;
    char    **str;

    fd = open(name, O_RDWR);
    y = ft_count_lines(name);
    str = malloc(sizeof(char *) * y);
    i = -1;
    while (++i < y)
        str[i] = get_next_line(fd);
    l->map = str;
    l->n_coin = 0;
    i = 0;
    fd = 0;
    while (fd < y)
    {
        i = 0;
        while (str[fd][i] && str[fd][i] != '\n')
        {
            if (str[fd][i] == '1')
                mlx_put_image_to_window(l->ptr, l->w_ptr, l->obs, i * 64, fd * 64);
            if (str[fd][i] == 'C')
            {
                mlx_put_image_to_window(l->player, l->w_ptr, l->backg, i * 64, fd * 64);
                mlx_put_image_to_window(l->ptr, l->w_ptr, l->coin, (i * 64) + 15.5, (fd * 64) + 15.5);
                l->n_coin++;
            }
            if (str[fd][i] == 'E')
            {
                mlx_put_image_to_window(l->player, l->w_ptr, l->backg, i * 64, fd * 64);
                mlx_put_image_to_window(l->ptr, l->w_ptr, l->ex, i * 64, fd * 64);
            }
            if (str[fd][i] == 'P')
            {
                mlx_put_image_to_window(l->player, l->w_ptr, l->backg, i * 64, fd * 64);
                mlx_put_image_to_window(l->ptr, l->w_ptr, l->player, i * 64, fd * 64);
                l->x = i * 64;
                l->y = fd * 64;
            }
            if (str[fd][i] == '0')
                mlx_put_image_to_window(l->player, l->w_ptr, l->backg, i * 64, fd * 64);
            i++;
        }
        fd++;
    }
}