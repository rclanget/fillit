#include "fillit.h"

static int  ft_check_around(t_tetri *tetri, int i)
{
    int j;

    j = 0;
    if (tetri->prev && tetri->prev->line[i] == '#')
        j++;
    if (tetri->next && tetri->next->line[i] == '#')
        j++;
    if (tetri->line[i - 1] && tetri->line[i - 1] == '#')
        j++;
    if (tetri->line[i + 1] && tetri->line[i + 1] == '#')
        j++;
    return (j > 0);
}

static int  ft_check_tetri(t_tetri *tetri)
{
    t_tetri *begin;
    int     i;
    int     nbr;
    int     lines;

    begin = tetri;
    nbr = 0;
    lines = 0;
    while (begin)
    {
        i = 0;
        while (begin->line[i])
        {
            if (begin->line[i] == '#' && ft_check_around(begin, i))
                nbr++;
            i++;
        }
        lines++;
        begin = begin->next;
    }
    return (((nbr == 4) && (lines == 4)));
}

void ft_check_list(t_lt *lt)
{
    t_lt *begin;

    begin = lt;
    while (begin)
    {
        if (!ft_check_tetri(begin->tetriminos))
            ft_exit("Error: bad tetriminos");
        begin = begin->next;
    }
}

int  check_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if ((line[i] != '.' && line[i] != '#' && i < 4))
            return (0);
        i++;
    }
    return ((i == 4));
}
