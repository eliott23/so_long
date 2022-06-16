#include <mlx.h>

typedef struct p{
    void *ptr;
    void *w_ptr;
    void *i_ptr;
}ptr;

int str_cmp(char *s1, char *s2)
{
    int i;

    i = 0;
    if (s1 && s2)
    {
        while (s1[i] && s2[i])
        {
            if (s1[i] != s2[i])
                return (0);
            i++;
        }
        if (!s1[i] && !s2[i])
            return (1);
    }
    return (0);
}

int map_protect(char *m_name)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (m_name[i])
    {
        while (m_name[i] && m_name[i] != '.')
            i++;
        if (m_name[i] == '.')
            j = i;
        if (m_name[i])
            i++;
    }
    if (m_name[j])
    {
        if (!str_cmp(".ber", m_name + j))
        {
            write(1, "Error\n", 6);
            exit(0);
        }
        return (1);
    }
    write (1, "Error\n", 6);
    exit(0);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (str)
    {
        while (str[i])
            i++;
        return (i);
    }
    return (0);
}

int rect(char *name)
{
    int     fd;
    char    *str;
    int     i;
    int     j;

    i = 0;
    j = 0;
    str = malloc(sizeof(char));
    fd = open(name, O_RDWR);
    while (str)
    {
        free(str);
        if (i != j)
            return (0);
        j = i;
        str = get_next_line(fd);
        i = ft_strlen(str);
    }
}

int	main(int argc, char **argv)
{
    map_protect(argv[1]);
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