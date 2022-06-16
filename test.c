#include <mlx.h>

typedef struct p{
    void *ptr;
    void *w_ptr;
    void *i_ptr;
}ptr;

int ft_protect(char *m_name)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (m_name[i])
    {
        while (m_name [i] && m_name[i] != '.')
            i++;
        j = i;
         i++;
    }
}

int	main(int argc, char **argv)
{
    int a = 64;
    ptr l;
    l.ptr = mlx_init();
    l.w_ptr = mlx_new_window(l.ptr, 1000, 1000, "lol");
    l.i_ptr = mlx_xpm_file_to_image(l.ptr, "grass.xpm", &a, &a);
    mlx_put_image_to_window(l.ptr, l.w_ptr, l.i_ptr, 64, 0);
    l.i_ptr = mlx_xpm_file_to_image(l.ptr, "plyr.xpm", &a, &a);
    mlx_put_image_to_window(l.ptr, l.w_ptr, l.i_ptr, 0, 0);
    mlx_loop(l.ptr);
}