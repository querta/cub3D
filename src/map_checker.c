/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:19:50 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/13 19:24:06 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char **map_copy(t_set *s)
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

int checkpoint(char **map, int y, int x)
{
	int len;

	len = 0;
	while (map[len])
		len++;
	if(x == (int)ft_strlen(map[y]) - 1)
		return (0);
	if(x == 0)
		return (0);
	if (y == 0)
		return (0);
	if (y == len -1)
		return (0);
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

// static void changecolor(char **map, int y, int x)
// {
// 	int size;

// 	size = 0;
// 	while (map[size])
// 		size++;
// 	// char p = '0';
// 	if (map[y][x] == '0')
// 		map[y][x] = 'x';
// 	if (y > 0)
// 		changecolor(map, y - 1, x);
// 	if((y + 1 < size - 1))
// 		changecolor(map, y + 1, y);
// 	if (x > 0)
// 		changecolor(map, y, x - 1);
// 	if (x + 1 < ((int)ft_strlen(map[y]) - 1))
// 		changecolor(map, y, x + 1);
// 	// changecolor(map, y - 1, x - 1);
// 	// changecolor(map, y - 1, x + 1);
// 	// changecolor(map, y + 1, x - 1);
// 	// changecolor(map, y + 1, x + 1);
// 	// return (1);
// }

int checkborders(char **map)
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
				if (checkpoint(map, i, k) == 0)
					return (0);
			}
			k++;
		}
		i++;
	}
	return (1);
}

int		map_checker(t_set *s)
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
	mapfiller(map, (int)s->pl.y, (int)s->pl.x);
	if (!checkborders(map))
	{
		freearr(map);
		return (0);
	}
	while (map[++i])
		ft_putendl_fd(map[i], 1);
	freearr(map);
	return (1);
}

// void floodfill( std::vector<std::vector<char>>& v, unsigned int x, unsigned int y, char r) {
//     char p = v[x][y];
//     v[x][y] = r;
//     if(x > 0 && v[x - 1][y] == p)
//         floodfill(v, x - 1, y, r);
//     if(x + 1 < v.size() && v[x + 1][y] == p)
//         floodfill(v, x + 1, y, r);
//     if(y > 0 && v[x][y - 1] == p)
//         floodfill(v, x, y - 1, r);
//     if(y + 1 < v[x].size() && v[x][y + 1] == p)
//         floodfill(v, x, y + 1, r);
// }