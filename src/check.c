/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:47:31 by rpinet            #+#    #+#             */
/*   Updated: 2016/12/30 16:27:46 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define CARRE		"##\n##\0"
#define BARRE_V 	"#\n#\n#\n#\0"
#define BARRE_H 	"####\0"
#define Z1			"##\n.##\0"
#define Z2			".##\n##\0"
#define Z3			".#\n##\n#\0"
#define Z4			"#\n##\n.#\0"
#define L_H1		"#\n###\0"
#define L_H2		"###\n#\0"
#define L_H3		"..#\n###\0"
#define L_H4		"###\n..#\0"
#define L_V1		"##\n#\n#\0"
#define L_V2		"#\n#\n##\0"
#define L_V3		".#\n.#\n##\0"
#define L_V4		"##\n.#\n.#\0"
#define T1			".#\n###\0"
#define T2			"#\n##\n#\0"
#define T3			"###\n.#\0"
#define T4			".#\n##\n.#\0"

char		**initbanque(void)
{
	char	**banque;

	if (!(banque = (char**)malloc(sizeof(char*) * 20)))
		ft_error("initBanque bad malloc");
	banque[0] = ft_strdup(CARRE);
	banque[1] = ft_strdup(BARRE_V);
	banque[2] = ft_strdup(BARRE_H);
	banque[3] = ft_strdup(Z1);
	banque[4] = ft_strdup(Z2);
	banque[5] = ft_strdup(Z3);
	banque[6] = ft_strdup(Z4);
	banque[7] = ft_strdup(L_H1);
	banque[8] = ft_strdup(L_H2);
	banque[9] = ft_strdup(L_H3);
	banque[10] = ft_strdup(L_H4);
	banque[11] = ft_strdup(L_V1);
	banque[12] = ft_strdup(L_V2);
	banque[13] = ft_strdup(L_V3);
	banque[14] = ft_strdup(L_V4);
	banque[15] = ft_strdup(T1);
	banque[16] = ft_strdup(T2);
	banque[17] = ft_strdup(T3);
	banque[18] = ft_strdup(T4);
	banque[19] = NULL;
	return (banque);
}

int			verifchar(char *line)
{
	char	*ptr;

	ptr = line;
	while (line && *ptr)
	{
		if (*ptr != '#' && *ptr != '.' && *ptr != '\n')
			return (0);
		ptr++;
	}
	return (1);
}

int			verifformat(char *line, int i)
{
	int		j;
	char	*ptr;

	i = 1;
	j = 1;
	ptr = line;
	while (ptr && *ptr)
	{
		if (j > (26 * 4 + 25))
			ft_error("more than 26 tetrominos");
		else if (i > 5)
			ft_error("line > 4");
		else if (j % 5 != 0 && *ptr == '\n' && i < 5)
			ft_error((i == 1) ? "line > 4" : "line < 4");
		else if (j % 5 == 0 && *ptr != '\n')
			ft_error("bad spacing between 2 tetrominos");
		if (*ptr == '\n')
		{
			i = 0;
			j++;
		}
		i++;
		ptr++;
	}
	return (1);
}
