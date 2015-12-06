#include "fillit.h"

#include "libft.h"
#include <string.h>
#include <unistd.h>

void ft_print_lt(t_info *info)
{
    t_lt    *begin_lt;
    t_tetri *begin_tetri;

    begin_lt = info->list;
    while (begin_lt)
    {
        ft_print("-> %c\n", begin_lt->letter);
        begin_tetri = begin_lt->tetriminos;
        while (begin_tetri)
        {
            // ft_print("%s\n", begin_tetri->line);
            begin_tetri = begin_tetri->next;
        }
        begin_lt = begin_lt->next;
    }
    ft_print("Size: %d\n", info->size);
}

int main(int ac, char **av)
{
    t_info info;

    info.list = NULL;
    info.size = 0;
    if (ac != 2)
        ft_exit("One argument please.");
    ft_parse(av[1], &info);
    ft_check_list(info.list);
    // ft_get_square();
    ft_print_lt(&info);
    ft_free_lt(info.list);
    // sleep(5);
    return (1);
}
