/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:19:50 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/16 18:46:17 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	char **map_copy(t_set *s)
{
	int i;
	char **map;

	i = 0;
	while (s->map[i])
		i++;
	if (!(map = (char **)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while(s->map[i])
	{
		map[i] = ft_strdup(s->map[i]);
		i++;
	}
	map[i] = 0;	
	return (map);
}

int		checker_map(t_set *s)
{
	char **map;
	int i;
	int x;
	int y;

	i = -1;
	x = 0;
	y = 0;

	map = map_copy(s);
	map[(int)s->pl.y][(int)s->pl.x] = '0';
	if(!checker_filler_map(s, map))
	{
		if (map)
			freearr(map);
		return (0);
	}
	while (map[++i])
		ft_putendl_fd(map[i], 1);
	if (map)
		freearr(map);
	return (1);
}
