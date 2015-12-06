#ifndef FILLIT_H
# define FILLIT_H

typedef struct      s_tetri
{
    char            *line;
    struct s_tetri  *prev;
    struct s_tetri  *next;
}                   t_tetri;

typedef struct      s_lt
{
    t_tetri         *tetriminos;
    char            letter;
    struct s_lt     *prev;
    struct s_lt     *next;
}                   t_lt;

void                ft_exit(char *msg);

t_lt                *ft_parse(char *name, t_lt *lt);

t_lt                *lst_add_tetri(t_lt *lt, t_tetri *tetri);
t_tetri             *lst_add_line(t_tetri *tetri, char *line);

void                ft_check_list(t_lt *lt);
int                 check_line(char *line);

void                ft_free_lt(t_lt *lt);

#endif //FILLIT_H
