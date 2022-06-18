#include "so_long.h"

void    ft_error()
{
    write(1, "Error\n", 6);
    exit(0);
}

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
            ft_error();
        return (1);
    }
    write(1, "Error\n", 6);
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

void    rect(char *name)
{
    int     fd;
    char    *str;
    int     i;
    int     j;
    int     count;

    i = 0;
    j = 0;
    count = 0;
    str = malloc(sizeof(char));
    fd = open(name, O_RDWR);
    while (str)
    {
        if (j == 0)
            j = i;
        free(str);
        if (i != j)
            ft_error();
        j = i;
        str = get_next_line(fd);
        i = ft_strlen(str);
        count++;
    }
    close(fd);
    if (count <= 1)
        ft_error();
}

int     ft_count_lines(char *name)
{
    int     fd;
    int     count;
    char    *str;

    count = -1;
    fd = open(name, O_RDWR);
    str = malloc(sizeof(char));
    while(str)
    {
        count++;
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    return (count);
}

void    check_line(char *str)
{
    int i;

    i = 0;
    while (str && str[i] && str[i] != '\n')
    {
        if (str[i] != '1')
            exit(2);
        i++;
    }
}

void    ft_closed(char *name)
{
    int     i;
    char    *str;
    int     fd;
    int     n_lines;

    i = 0;
    n_lines = ft_count_lines(name);
    fd = open(name, O_RDWR);
    str = get_next_line(fd);
    check_line(str);
    while (--n_lines)
    {
        i = 0;
        free(str);
        str = get_next_line(fd);
        if (str[i] != '1')
            exit(2);
        while (str[i] && str[i] != '\n' && str[i + 1] != '\n')
            i++;
        if (str[i] != '1')
            exit(2);
    }
    check_line(str);
    close(fd);
}

void    m_protect2(char *name)
{
    int     fd;
    char    *str;
    int     i;
    struct elements el;

    el.C = 0;
    el.E = 0;
    el.P = 0;
    fd = open(name, O_RDWR);
    str = malloc(sizeof(char));
    while (str)
    {
        i = 0;
        free(str);
        str = get_next_line(fd);
        while (str && str[i] && str[i] != '\n')
        {
            if (str[i] == 'E')
                el.E = 1;
            if (str[i] == 'C')
                el.C = 1;
            if (str[i] == 'P')
                el.P = 1;
            i++;
        }
    }
    if (!el.E || !el.C || !el.P)
        ft_error();
    close(fd);
}

int ft_test(int c, ptr *l)
{
    fprintf(stderr, "%d\n", c);
    if (c == 53)
        exit(0);
    if (c == 124)
        mlx_put_image_to_window(l->ptr, l->w_ptr, l->player, 64, 0);
    return (0);
}

int x_count(char *name)
{
    int     i;
    int     fd;
    char    *str;

    fd = open(name, O_RDWR);
    i = 0;
    str = get_next_line(fd);
    while (str && str[i] && str[i] != '\n')
        i++;
    return (i);
}

int	main(int argc, char **argv)
{
    argc = 0;
    map_protect(argv[1]);
    m_protect2(argv[1]);
    rect(argv[1]);
    ft_closed(argv[1]);
    int a = 64;
    ptr l;
    l.ptr = mlx_init();
    l.w_ptr = mlx_new_window(l.ptr, x_count(argv[1]) * 64, ft_count_lines(argv[1]) * 64, "lol");
    l.backg = mlx_xpm_file_to_image(l.ptr, "grass.xpm", &a, &a);
    l.player= mlx_xpm_file_to_image(l.ptr, "plyr.xpm", &a, &a);
    l.obs = mlx_xpm_file_to_image(l.ptr, "obs.xpm", &a, &a);
    l.coin= mlx_xpm_file_to_image(l.ptr, "coin.xpm", &a, &a);
    l.ex = mlx_xpm_file_to_image(l.ptr, "exit.xpm", &a, &a);
    str_map(argv[1], &l);
    mlx_key_hook(l.w_ptr, ft_test, &a);
    mlx_loop(l.ptr);
}