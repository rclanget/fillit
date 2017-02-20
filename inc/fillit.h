/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:49:18 by dle-norm          #+#    #+#             */
/*   Updated: 2016/12/30 17:51:13 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

//# define BUFF_SIZE 5
# define COLOR 0
# define ERROR 0
# define DEBUG 0
# define SLEEP 1
# define DEBUG_SCOP 10
# define POSX (pos->x + search.x)
# define POSY (pos->y + search.y)
# define BUFF_SIZE_GNL 500

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_map
{
	int				form;
	int				pos;
	int				lock;
	char			letter;
	int				*coord1;
	int				*coord2;
	int				*coord3;
	int				*coord4;
	char			*piece;
	int				height;
	int				width;
	struct s_map	*next;
	struct s_map	*back;
}					t_map;

typedef struct		s_grid
{
	int				min;
	int				piece;
	int				nb_piece;
	char			**map;
}					t_grid;

typedef struct		s_int
{
	int				i;
	int				j;
	int				k;
	int				l;
	int				m;
}					t_int;

void				comptehastag(char *line);
t_grid				*searchbest3(t_grid *g, t_coord posleftmin, char place);
int					filltmp2(t_grid *g, t_coord pos, int ret, char place);
t_grid				*searchbest2(t_grid *g);
int					comparebanque(t_int *ite, char *line, char **banq);
t_map				*addmap(t_map *map, char *line, char **banq);
t_map				*parsor(t_map *map, char *tab, char **banq);
t_map				*verifmap(t_map *map, char *tab, char **banq);
int					get_next_line(int fd, char **line);
char				**initbanque();
int					checktetro(t_grid g, t_coord *pos, char *tetro);
int					verifchar(char *line);
int					verifformat(char *line, int i);
void				ft_error(char *text);
int					emptyline(char *s);
void				printbanq(char **banq);
void				fillcoord(t_coord *coord, int x, int y);
void				ft_freetab(char **tab);
int					tmpsize(t_grid g, t_coord *pos, char *tetro);
void				cleangrid(t_grid *g);
int					getheight(char *tetro);
int					getsize(char **tab);
void				getsol(t_grid *g);
void				searchplace(t_grid *g, t_map *tetro, char **banq);
void				debugend(int smin);
void				debugsideinfo(int smin, int x, int y, char place);
void				debugtetro(int pos);
void				printlistform(t_map *list, char **banq);
void				printgridtest(t_grid sol);
void				improve(t_grid *g, t_map *map, char **banq);
void				filltetro(t_grid *g, t_coord *pos, char *form, char c);
int					getwidth(char *tetro);
int					ft_sqrt(t_map *map);
t_grid				resolv(t_map *map, char **banq);
void				free_grid(t_grid *grid);
void				print_grid(t_grid *grid);
t_grid				ft_init_grid(t_map *map);
int					ft_resolve_map(t_grid *grid, t_map *map, int x, int y);
void				ft_remove(t_grid *grid, int y, int x, t_map *map);

#endif
