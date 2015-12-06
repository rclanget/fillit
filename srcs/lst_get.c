#include "fillit.h"

#include <stdlib.h>

t_map *get_map_pos(t_map *map, int pos)
{
    t_map *begin;

    begin = map;
    while (begin)
    {
        if (begin->pos == pos)
            return (begin);
        begin = begin->next;
    }
    return (NULL);
}
