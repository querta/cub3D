/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:19:50 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/25 13:51:10 by mmonte           ###   ########.fr       */
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

	map = map_copy(s);
	map[(int)s->pl.y][(int)s->pl.x] = '0';
	if(!checker_filler_map(s, map))
		return (0);
	if (map)
		freearr(map);
	return (1);
}