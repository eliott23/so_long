#include "so_long.h"

void    str_map(char *name, ptr *l)
{
    int     y;
    int     i;
    int     fd;
    int     c_count;
    char    **str;

    c_count = 0;
    fd = open(name, O_RDWR);
    y = ft_count_lines(name);
    str = malloc(sizeof(char *) * y);
    i = -1;
    while (++i < y)
        str[i] = get_next_line(fd);
    i = 0;
    fd = 0;
    while (fd < y)
    {
        i = 0;
        while (str[fd][i] && str[fd][i] != '\n')
        {
            // if (str[fd][i] == '1')
            //     mlx_put_image_to_window(l->ptr, l->w_ptr, l->obs, i * 64, fd * 64);
            // if (str[fd][i] == 'C')
            // {
            //     mlx_put_image_to_window(l->ptr, l->w_ptr, l->coin, i * 64, fd * 64);
            //     c_count++;
            // }
            // if (str[fd][i] == 'E')
            //     mlx_put_image_to_window(l->ptr, l->w_ptr, l->ex, i * 64, fd * 64);
            if (str[fd][i] == 'P')
                mlx_put_image_to_window(l->ptr, l->w_ptr, l->player, i * 64, fd * 64);
            if (str[fd][i] == '0')
                mlx_put_image_to_window(l->player, l->w_ptr, l->backg, i * 64, fd * 64);
            i++;
        }
        fd++;
    }
}