/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:47:34 by dle-norm          #+#    #+#             */
/*   Updated: 2016/12/30 16:28:07 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_error(char *inserttext)
{
	ft_putendl("error");
	if (inserttext && ERROR == 1)
	{
		ft_putstr(" : ");
		ft_putendl(inserttext);
	}
	exit(0);
}

int			emptyline(char *s)
{
	char			*ptr;

	if (!s)
		return (0);
	ptr = s;
	while (s && *s)
	{
		if (*s != '.')
			return (1);
		s++;
	}
	return (0);
}

void		printbanq(char **banq)
{
	int		i;

	i = -1;
	while (++i < 19)
	{
		ft_putstr("tetromino [");
		ft_putnbr(i);
		ft_putstr("]\n");
		ft_putendl(banq[i]);
	}
}

void		fillcoord(t_coord *coord, int x, int y)
{
	coord->x = x;
	coord->y = y;
}

void		ft_freetab(char **tab)
{
	int		j;

	j = 0;
	while (tab[j] != NULL)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}
