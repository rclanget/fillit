#include "fillit.h"

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

t_lt *ft_parse(char *name, t_lt *lt)
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
        if (!ft_strcmp(line, "") && !(tetri = NULL))
        {
            i = 0;
            free(line);
            continue ;
        }
        if ((i++ > 3) || !check_line(line))
            ft_exit("Error: bad tetriminos");
        if ((tetri = lst_add_line(tetri, line)) && i == 4)
            lt = lst_add_tetri(lt, tetri);
        free(line);
    }
    close(fd);
    return (lt);
}
