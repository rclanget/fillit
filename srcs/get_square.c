#include "fillit.h"

#include <stdlib.h>

void create_map(t_info *info)
{
    t_map   *map;
    int     size;

    size = (info->map_size * info->map_size);
    map = NULL;
    while (size > 0)
    {
        map = lst_add_map(map, '.', info->map_size);
        --size;
    }
    info->map = map;
}

void ft_get_square(t_info *info)
{
    // Creer tableau de taille x
    create_map(info);
    // tant qu'on arrive a placer des tetriminos, on boucle
    // Si toutes les pieces sont placees on retourne le carre
    // Sinon on cree un tableau plus grand et on recommence
}
