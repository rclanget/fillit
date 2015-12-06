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

typedef struct      s_map
{
    char            c;
    int             pos;
    struct s_map    *up;
    struct s_map    *down;
    struct s_map    *next;
    struct s_map    *prev;
}                   t_map;

typedef struct      s_info
{
    t_lt            *list;
    t_map           *map;
    int             map_size;
    int             size;
}                   t_info;

void                ft_exit(char *msg);

void                ft_parse(char *name, t_info *info);

t_lt                *lst_add_tetri(t_info *info, t_tetri *tetri);
t_tetri             *lst_add_line(t_tetri *tetri, char *line);
t_map               *lst_add_map(t_map *map, char c, int size);

t_map               *get_map_pos(t_map *map, int pos);

void                ft_check_list(t_lt *lt);
int                 check_line(char *line);

void                ft_free(t_info *info);

void                ft_get_square(t_info *info);

#endif //FILLIT_H
