#include "fillit.h"
#include <string.h>

#include "libft.h"

#include <unistd.h>

void ft_print_lt(t_lt *lt)
{
    t_lt    *begin_lt;
    t_tetri *begin_tetri;

    begin_lt = lt;
    while (begin_lt)
    {
        begin_tetri = begin_lt->tetriminos;
        while (begin_tetri)
        {
            ft_print("%s\n", begin_tetri->line);
            begin_tetri = begin_tetri->next;
        }
        begin_lt = begin_lt->next;
    }
}

int main(int ac, char **av)
{
    t_lt *lt;

    lt = NULL;
    if (ac != 2)
        ft_exit("One argument please.");
    lt = ft_parse(av[1], lt);
    ft_check_list(lt);
    // ft_get_square();
    ft_print_lt(lt);
    ft_free_lt(lt);
    // sleep(5);
    return (1);
}
