/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_filler_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:23:46 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/03 17:37:48 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_cross(char **map, int y, int x)
{
	if (x > (int)ft_strlen(map[y + 1]) - 1)
		return (0);
	if (x > (int)ft_strlen(map[y - 1]) - 1)
		return (0);
	if (map[y - 1][x] == '\0' || map[y - 1][x] == ' ')
		return (0);
	if (map[y + 1][x] == '\0' || map[y + 1][x] == ' ')
		return (0);
	if (map[y][x - 1] == '\0' || map[y][x - 1] == ' ')
		return (0);
	if (map[y][x + 1] == '\0' || map[y][x + 1] == ' ')
		return (0);
	return (1);
}

static int	check_corners(char **map, int y, int x)
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

static int	check_filled_point(char **map, int y, int x)
{
	int len;

	len = 0;
	while (map[len])
		len++;
	if (y < len - 1 && y > 0)
	{
		if (x < (int)ft_strlen(map[y]) && x > 0)
		{
			if (check_corners(map, y, x))
			{
				if (check_cross(map, y, x))
					return (1);
			}
		}
	}
	return (0);
}

int			checkborders(char **map)
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
			if (map[i][k] == 'x' || map[i][k] == '2')
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

int			mapfiller(char **map, int y, int x)
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
