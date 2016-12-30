/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:11:41 by dle-norm          #+#    #+#             */
/*   Updated: 2016/12/30 16:54:05 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int g_coord1[19][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 1}, {0, 1}, {0, 0},
	{0, 0}, {0, 0}, {0, 2}, {0, 0}, {0, 0}, {0, 0}, {0, 1}, {0, 0}, {0, 1},
	{0, 0}, {0, 0}, {0, 1}};

int g_coord2[19][2] = {{0, 1}, {1, 0}, {0, 1}, {0, 1}, {0, 2}, {1, 0}, {1, 0},
	{1, 0}, {0, 1}, {1, 0}, {0, 1}, {0, 1}, {1, 0}, {1, 1}, {0, 1}, {1, 0},
	{1, 0}, {0, 1}, {1, 0}};

int g_coord3[19][2] = {{1, 0}, {2, 0}, {0, 2}, {1, 1}, {1, 0}, {1, 1}, {1, 1},
	{1, 1}, {0, 2}, {1, 1}, {0, 2}, {1, 0}, {2, 0}, {2, 0}, {1, 1}, {1, 1},
	{1, 1}, {0, 2}, {1, 1}};

int g_coord4[19][2] = {{1, 1}, {3, 0}, {0, 3}, {1, 2}, {1, 1}, {2, 0}, {2, 1},
	{1, 2}, {1, 0}, {1, 2}, {1, 2}, {2, 0}, {2, 1}, {2, 1}, {2, 1}, {1, 2},
	{2, 0}, {1, 1}, {2, 1}};

t_map	*parsor(t_map *map, char *tab, char **banq)
{
	char	*temp;
	int		j;

	if ((temp = (char *)malloc(sizeof(char) * ft_strlen(tab))))
	{
		while (*tab)
		{
			j = 0;
			while (*tab != '\n' || !ft_strchr("\n", *(tab + 1)))
				temp[j++] = *(tab++);
			temp[j] = '\0';
			if (j != 19)
				ft_error("bad tetrominos");
			map = addmap(map, temp, banq);
			while (*tab == '\n')
				tab++;
		}
		free(temp);
	}
	return (map);
}

t_map	*init_elem(char *line, char **banq)
{
	static int	i = 0;
	t_map		*newt;
	t_int		*ite;

	if ((ite = (t_int*)malloc(sizeof(t_int))))
	{
		i++;
		comptehastag(line);
		if ((newt = (t_map*)malloc(sizeof(t_map))))
		{
			newt->form = comparebanque(ite, line, banq);
			newt->coord1 = g_coord1[newt->form];
			newt->coord2 = g_coord2[newt->form];
			newt->coord3 = g_coord3[newt->form];
			newt->coord4 = g_coord4[newt->form];
			newt->pos = i;
			newt->piece = ft_strdup(banq[newt->form]);
			newt->next = NULL;
			newt->back = NULL;
			return (newt);
		}
	}
	return (0);
}

t_map	*addmap(t_map *map, char *line, char **banq)
{
	t_map	*tmp;
	t_map	*newt;

	if ((newt = init_elem(line, banq)))
	{
		if (!map)
			map = newt;
		else
		{
			tmp = map;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = newt;
			tmp->next->back = tmp;
		}
	}
	return (map);
}

t_int	*comparebanque2(t_int *ite, char *line, char **banq)
{
	ite->k = 0;
	if (line[ite->j] == banq[ite->i][ite->k])
	{
		ite->l = ite->j;
		while (line[ite->j] == banq[ite->i][ite->k]
				&& (line[ite->j] != '\0' || banq[ite->i][ite->k] != '\0'))
		{
			if (line[ite->j] == '#')
				ite->m = 1;
			ite->j++;
			ite->k++;
			if (banq[ite->i][ite->k] == '\n' && line[ite->j] != '#')
			{
				ite->j = ite->l + 5;
				ite->l = ite->j;
				ite->k++;
			}
		}
		ite->j = ite->l + 1;
	}
	else
		ite->j++;
	return (ite);
}

int		comparebanque(t_int *ite, char *line, char **banq)
{
	ite->i = 0;
	while (ite->i != 19)
	{
		ite->j = 0;
		ite->m = 0;
		while (line[ite->j] != '\0')
		{
			ite = comparebanque2(ite, line, banq);
			if (banq[ite->i][ite->k] == '\0')
			{
				while (line[ite->j] != '\0')
				{
					if (line[ite->j] == '#')
						break ;
					ite->j++;
				}
				return (ite->i);
			}
			else if (ite->m == 1)
				break ;
		}
		ite->i++;
	}
	ft_error("No tetrominos form's");
	return (27);
}
