#include "fillit.h"

int main(int ac, char **av)
{
    if (ac != 2)
        ft_exit("One argument please.");
    ft_parse(av[1]);
    // ft_get_square();
    // ft_print();
    return (1);
}
