#include "fillit.h"

#include <stdlib.h>

void ft_free_tetri(t_tetri *tetri)
{
    if (tetri && tetri->next)
        ft_free_tetri(tetri->next);
    free(tetri->line);
    free(tetri);
}

void ft_free_lt(t_lt *lt)
{
    if (lt && lt->next)
        ft_free_lt(lt->next);
    ft_free_tetri(lt->tetriminos);
    free(lt);
}
