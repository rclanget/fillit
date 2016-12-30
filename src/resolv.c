/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:18:09 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/30 17:47:48 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_enough_space(t_grid *grid, int y, int x, t_map *map)
{
	if ((y + map->coord1[0] < grid->min) && (x + map->coord1[1] < grid->min)
	&& grid->map[y + map->coord1[0]][x + map->coord1[1]] == '.')
	{
		if ((y + map->coord2[0] < grid->min) && (x + map->coord2[1] < grid->min)
		&& grid->map[y + map->coord2[0]][x + map->coord2[1]] == '.')
		{
			if ((y + map->coord3[0] < grid->min)
			&& (x + map->coord3[1] < grid->min)
			&& grid->map[y + map->coord3[0]][x + map->coord3[1]] == '.')
			{
				if ((y + map->coord4[0] < grid->min)
				&& (x + map->coord4[1] < grid->min)
				&& grid->map[y + map->coord4[0]][x + map->coord4[1]] == '.')
				{
					return (1);
				}
			}
		}
	}
	return (0);
}

int		ft_put_piece_to_position(t_grid *grid, int y, int x, t_map *map)
{
	grid->map[y + map->coord1[0]][x + map->coord1[1]] = map->letter;
	grid->map[y + map->coord2[0]][x + map->coord2[1]] = map->letter;
	grid->map[y + map->coord3[0]][x + map->coord3[1]] = map->letter;
	grid->map[y + map->coord4[0]][x + map->coord4[1]] = map->letter;
	return (1);
}

int		ft_bestfit(t_grid *grid, t_map *map, int *y, int *x)
{
	while (*y < grid->min)
	{
		while (*x < grid->min)
		{
			if (ft_check_enough_space(grid, *y, *x, map))
			{
				ft_put_piece_to_position(grid, *y, *x, map);
				map->lock = 1;
				grid->piece++;
				if (!ft_resolve_map(grid, map, 0, 0))
				{
					ft_remove(grid, *y, *x, map);
					map->lock = 0;
					grid->piece--;
				}
				else
					return (1);
			}
			(*x)++;
		}
		*x = 0;
		(*y)++;
	}
	return (0);
}

int		ft_resolve_map(t_grid *grid, t_map *map, int x, int y)
{
	t_map *tmp_map;

	tmp_map = map;
	if (grid->piece == grid->nb_piece)
		return (1);
	while (tmp_map)
	{
		if (!tmp_map->lock && (ft_bestfit(grid, tmp_map, &x, &y)))
			return (1);
		tmp_map = tmp_map->next;
	}
	return (0);
}

t_grid	resolv(t_map *map, char **banq)
{
	t_grid	grid;

	grid = ft_init_grid(map);
	while (!ft_resolve_map(&grid, map, 0, 0))
		grid.min++;
	return (grid);
}
