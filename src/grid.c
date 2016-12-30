/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:17:23 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/30 16:44:47 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_remove(t_grid *grid, int y, int x, t_map *map)
{
	grid->map[y + map->coord1[0]][x + map->coord1[1]] = '.';
	grid->map[y + map->coord2[0]][x + map->coord2[1]] = '.';
	grid->map[y + map->coord3[0]][x + map->coord3[1]] = '.';
	grid->map[y + map->coord4[0]][x + map->coord4[1]] = '.';
	map->lock = 0;
}

void	print_grid(t_grid *grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (grid->map[i] && i < grid->min)
	{
		while (j < grid->min)
			ft_putchar(grid->map[i][j++]);
		ft_putchar('\n');
		j = 0;
		++i;
	}
}

int		ft_sqrt(t_map *map)
{
	int		ret;
	int		i;
	t_map	*ptr;

	i = 0;
	ptr = map;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	ret = 1;
	while ((ret * ret) < (i * 4))
		ret++;
	return (ret);
}

char	**ft_bpoint(int size)
{
	char	**tab;
	int		i;
	int		j;

	tab = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	i = 0;
	while (i < size)
	{
		tab[i] = ft_memalloc(sizeof(char) * (size + 1));
		j = 0;
		while (j < size)
			tab[i][j++] = '.';
		tab[i++][j] = 0;
	}
	tab[i] = 0;
	return (tab);
}

t_grid	ft_init_grid(t_map *map)
{
	t_grid	grid;
	int		nb_piece;
	t_map	*tmp_map;

	nb_piece = 0;
	tmp_map = map;
	grid.min = ft_sqrt(tmp_map);
	while (tmp_map && ++nb_piece)
	{
		tmp_map->letter = 64 + nb_piece;
		tmp_map->lock = 0;
		tmp_map = tmp_map->next;
	}
	grid.nb_piece = nb_piece;
	grid.piece = 0;
	grid.map = ft_bpoint(40);
	return (grid);
}
