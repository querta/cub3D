/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_filler_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:23:46 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/15 18:43:20 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int check_corner(char **map, int y, int x)
{
	if (map[y + 1][x + 1] == '\0' || map[y + 1][x + 1] == ' ')
		return (0);
	if (map[y + 1][x - 1] == '\0' || map[y + 1][x - 1] == ' ')
		return (0);
	if (map[y - 1][x - 1] == '\0' || map[y - 1][x - 1] == ' ')
		return (0);
	if (map[y - 1][x + 1] == '\0' || map[y - 1][x + 1] == ' ')
		return (0);
	return (1);
}

static int check_filled_point(char **map, int y, int x)
{
	int len;

	len = 0;
	while (map[len])
		len++;
	printf("x=%d, y=%d, len=%d\n", x, y, len);
	if (y < len -1 && y > 0)
	{
		printf("x=%d, y=%d\n", x, y);
		if (x < (int)ft_strlen(map[y]) && x > 0)
		{
			printf("tut x=%d, y=%d\n", x, y);
			if (check_corner(map, y, x))
				return (1);
		}
	}
	return (0);
}

static int checkborders(char **map)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == 'x')
			{
				if (check_filled_point(map, i, k) == 0)
					return (0);	
			}
			k++;
		}
		i++;
	}
	return (1);
}

static int mapfiller(char **map, int y, int x)
{
	if (map[y][x] != '0')
		return (0);
	if (map[y][x] == '0')
		map[y][x] = 'x';
	if (x > 0)
		mapfiller(map, y, x - 1);
	if (x < (int)ft_strlen(map[y]))
		mapfiller(map, y, x + 1);
	if (y > 0)
		mapfiller(map, y - 1, x);
	if (y < arrsize(map) - 1)
		mapfiller(map, y + 1, x);
	if (y < arrsize(map) - 1 && x < (int)ft_strlen(map[y]))
		mapfiller(map, y + 1, x + 1);
	if (x > 0 && y > 0)
		mapfiller(map, y - 1, x - 1);
	if (y > 0 && x < (int)ft_strlen(map[y]))
		mapfiller(map, y - 1, x + 1);
	if (x > 0 && y < arrsize(map) - 1)
		mapfiller(map, y + 1, x - 1);
	return (1);
}

int checker_filler_map(t_set *s, char **map)
{
	mapfiller(map, (int)s->pl.y, (int)s->pl.x);
	if (!checkborders(map))
	{
		freearr(map);
		return (0);
	}
	return (1);
}