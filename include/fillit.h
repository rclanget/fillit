#ifndef FILLIT_H
# define FILLIT_H

typedef struct      s_tetri
{
    char            *line;
    struct s_tetri  *next;
}                   t_tetri;

typedef struct      s_lt
{
    t_tetri         *tetriminos;
    struct s_list   *next;
}                   t_lt;

void                ft_exit(char *msg);
t_tetri             *ft_parse(char *name);

#endif //FILLIT_H
