#include "fillit.h"

#include "libft.h"
#include <stdlib.h>

t_lt *lst_add_tetri(t_info *info, t_tetri *tetri)
{
    t_lt *new;

    if (!tetri)
        return (info->list);
    new = (t_lt *)malloc(sizeof(t_lt));
    new->tetriminos = tetri;
    new->next = info->list ? info->list : NULL;
    new->prev = info->list ? new : NULL;
    new->letter = info->list ? new->next->letter + 1 : 'A';
    info->size++;
    return (new);
}

t_tetri *lst_add_line(t_tetri *tetri, char *line)
{
    t_tetri *begin;
    t_tetri *new;

    new = (t_tetri *)malloc(sizeof(t_tetri));
    new->line = ft_strdup(line);
    new->next = NULL;
    new->prev = NULL;
    if ((begin = tetri))
    {
        while (begin->next)
            begin = begin->next;
        if ((begin->next = new))
            new->prev = begin;
        return (tetri);
    }
    else
        return (new);
}
