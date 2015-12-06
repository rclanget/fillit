#include "fillit.h"

#include "libft.h"
#include <stdlib.h>

t_lt *lst_add_tetri(t_lt *lt, t_tetri *tetri)
{
    t_lt *new;

    if (!tetri)
        return (lt);
    new = (t_lt *)malloc(sizeof(t_lt));
    new->tetriminos = tetri;
    new->next = lt ? lt : NULL;
    return (new);
}

t_tetri *lst_add_line(t_tetri *tetri, char *line)
{
    t_tetri *begin;
    t_tetri *new;

    new = (t_tetri *)malloc(sizeof(t_tetri));
    new->line = ft_strdup(line);
    new->next = NULL;
    if ((begin = tetri))
    {
        while (begin->next)
            begin = begin->next;
        begin->next = new;
        return (tetri);
    }
    else
        return (new);
}
