#include "fillit.h"

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

void ft_parse(char *name, t_info *info)
{
    t_tetri *tetri;
    char    *line;
    int     fd;
    int     i;

    tetri = NULL;
    fd = open(name, O_RDONLY);
    i = 0;
    while (get_next_line(fd, &line) > 0)
    {
        if (i == 4 && !(tetri = NULL))
        {
            i = 0;
            free(line);
            continue ;
        }
        if ((i++ > 3) || !check_line(line))
            ft_exit("Error: bad tetriminos");
        if ((tetri = lst_add_line(tetri, line)) && i == 4)
            info->list = lst_add_tetri(info, tetri);
        free(line);
    }
    if (i != 4 && !close(fd))
        ft_exit("Error: bad tetriminos");
}
