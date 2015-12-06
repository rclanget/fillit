#include "fillit.h"

int  ft_check_tetri(t_tetri *tetri)
{
    //
    // Il faut encore checker que chaque bloc est en contact avec un autre
    // bloc sur un de ses cotes
    // 
    t_tetri *begin;
    int     i;
    int     nbr;

    begin = tetri;
    nbr = 0;
    while (begin)
    {
        i = 0;
        while (begin->line[i])
        {
            if (begin->line[i] == '#')
                nbr++;
            i++;
        }
        begin = begin->next;
    }
    return ((nbr == 4));
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
        if (line[i] != '.' && line[i] != '#')
            return (0);
        i++;
    }
    return ((i == 4));
}
