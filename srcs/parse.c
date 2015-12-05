#include "fillit.h"

#include "libft.h"
#include <fcntl.h>

int     check_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '.' && line[i] != '#')
            return (0);
        i++;
    }
    return ((i == 4));
}
t_tetri *ft_parse(char *name)
{
    t_tetri *begin;
    char    *line;
    int     fd;
    int     i;

    begin = NULL;
    line = NULL;
    fd = open(name, O_RDONLY);
    i = 0;
    while (get_next_line(fd, &line) > 0)
    {
        if (!ft_strcmp(line, ""))
        {
            i = 0;
            continue ;
        }
        if ((i++ > 3) || !check_line(line))
            ft_exit("Error: bad tetriminos");
    }
    return (begin);
}
