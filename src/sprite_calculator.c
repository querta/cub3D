/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_calculator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 18:33:24 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/26 19:18:17 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	sort_sprites(t_set *s)
// {
// 	int i;
// 	t_spr *tmp;

// 	i = 0;
// 	while ()
// }

void sprite_calculator(t_set *s, t_point *map)
{
	double distance;
	int i;

	(void)map;
	i = 0;
	while (i < s->sprites)
	{
		distance = ((s->pl.y - s->spr[i].x) * (s->pl.y - s->spr[i].x) + (s->pl.x - s->spr[i].y) * (s->pl.x - s->spr[i].y));
		s->spr[i].dist =  distance;
		i++;
	}
	// sort_sprites(s);
		// printf("spr[%d].dist=%f\n", i, s->spr[i].dist);
		// distance = ((s->pl.y - map->x) * (s->pl.y - map->x) + (s->pl.x - map->y) * (s->pl.x - map->y));
	// printf("map.x=%d, map.y=%d, pl.x=%f, pl.y=%f, spr.x=%f, spr.y=%f\n", map->x, map->y, s->pl.x, s->pl.y, s->spr[0].x, s->spr[0].y);
	// new_sprite(map->x, map->y, distance);
	// ft_lstadd_back(&set->mlist, ft_lstnew(line));
	// printf("dist=%f\n", distance);
	// spriteDistance[i] = ((posX - sprite[i].x) * (posX - sprite[i].x) + (posY - sprite[i].y) * (posY - sprite[i].y)); //sqrt not taken, unneeded
}

void save_sprites(t_set *s)
{
	int i;
	int k;
	int n;

	i = 0;
	n = 0;
	while (s->map[i])
	{
		k = 0;
		while (s->map[i][k])
		{
			if (s->map[i][k] == '2')
			{
				s->spr[n].x = i;
				s->spr[n].y = k;
				n++;
			}
			k++;
		}
		i++;
	}
}