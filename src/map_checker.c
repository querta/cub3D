/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:19:50 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/08 18:11:30 by mmonte           ###   ########.fr       */
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

//  Заливка (элемент, заменяемый цвет, цвет заливки):
//  1. Если цвет элемента не заменяемый цвет, возврат.
//  2. Установить цвет элемента в цвет заливки.
//  3. Заливка (шаг на запад от элемента, заменяемый цвет, цвет заливки).
//     Заливка (шаг на восток от элемента, заменяемый цвет, цвет заливки).
//     Заливка (шаг на север от элемента, заменяемый цвет, цвет заливки).
//     Заливка (шаг на юг от элемента, заменяемый цвет, цвет заливки).
//     {для связности по 8 направлениям - ещё четыре вызова по диагоналям}
//  4. Возврат.

// @todo: как-то надо фиксануть, чтобы не рисовало когда есть дырка в стене
static int changecolor(char **map, int y, int x)
{
	if (map[y][x] != '0')
		return (1);
	map[y][x] = 'x';
	changecolor(map, y, x - 1);
	changecolor(map, y, x + 1);
	changecolor(map, y - 1, x);
	changecolor(map, y + 1, x);
	// changecolor(map, y - 1, x - 1);
	// changecolor(map, y - 1, x + 1);
	// changecolor(map, y + 1, x - 1);
	// changecolor(map, y + 1, x + 1);
	return (1);
}


// static void changecolor(char **map, int y, int x)
// {
// 	int size;

// 	size = 0;
// 	while (map[size])
// 		size++;
// 	char p = map[y][x];
// 	map[y][x] = 'x';
// 	// if (y > 0 && map[y -1][x] == p)
// 	// 	changecolor(map, y - 1, x);
// 	// if((y + 1 < size - 1) && map[y+1][x] == p)
// 	// 	changecolor(map, y + 1, y);
// 	if (x > 0 && map[y][x - 1] == p)
// 		changecolor(map, y, x - 1);
// 	if (x + 1 < (int)ft_strlen(map[y]) && map[y][x + 1] == p)
// 		changecolor(map, y, x + 1);
// 	// changecolor(map, y - 1, x - 1);
// 	// changecolor(map, y - 1, x + 1);
// 	// changecolor(map, y + 1, x - 1);
// 	// changecolor(map, y + 1, x + 1);
// 	// return (1);
// }

int		map_checker(t_set *s)
{
	char **map;
	int i;
	int x;
	int y;

	i = -1;
	x = 0;
	y = 0;
	// map = make_map(s, ft_lstsize(s->mlist));
	map = map_copy(s);
	map[(int)s->pl.y][(int)s->pl.x] = '0';
	// changecolor(map, (int)s->pl.y, (int)s->pl.x);
	changecolor(map, (int)s->pl.y, (int)s->pl.x);
	while (map[++i])
		ft_putendl_fd(map[i], 1);
	// paint(map[])

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