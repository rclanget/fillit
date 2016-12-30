/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:48:01 by dle-norm          #+#    #+#             */
/*   Updated: 2016/12/30 16:49:45 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*verifmap(t_map *map, char *tab, char **banq)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
		if (!ft_strchr("#.\n", tab[i++]))
			ft_error("bad tetrominos");
	map = parsor(map, tab, banq);
	return (map);
}

char		*readtetromino(char *file)
{
	int		fd;
	char	*line;
	char	*tab;
	char	*temp;

	tab = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error("open fail");
	while (get_next_line(fd, &line) > 0)
	{
		if (!verifchar(line))
			ft_error("bad character");
		temp = NULL;
		temp = ft_strjoin(tab, line);
		free(tab);
		tab = NULL;
		tab = ft_strjoin(temp, "\n");
		free(temp);
		temp = NULL;
	}
	close(fd);
	return (tab);
}

void		launch(int ac, char **av)
{
	char	**banq;
	char	*all;
	t_map	*map;
	t_grid	grid;

	all = readtetromino(av[1]);
	if (!all || !ft_strcmp(all, ""))
		ft_error("empty file");
	if (!verifformat(all, 0))
		ft_error("format");
	banq = initbanque();
	map = NULL;
	map = verifmap(map, all, banq);
	grid = resolv(map, banq);
	print_grid(&grid);
	ft_freetab(banq);
	free(all);
	ft_freetab(grid.map);
}

int			main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putendl("usage : ./fillit [valid file with tetrominos]");
		if (DEBUG)
			ft_putendl("\tempty argument");
	}
	else if (ac > 2)
	{
		ft_putendl("usage : ./fillit [valid file with tetrominos]");
		if (DEBUG)
			ft_putendl("\ttoo many argument");
	}
	else
		launch(ac, av);
	return (0);
}
