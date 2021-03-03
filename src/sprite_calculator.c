/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_calculator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 18:33:24 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/03 17:39:03 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sort_sprites(t_set *s)
{
	int			i;
	int			k;
	t_curspr	tmp;

	i = 0;
	while (i < s->sp->count)
	{
		k = s->sp->count - 1;
		while (k >= i)
		{
			if (s->spr[k - 1].dist <= s->spr[k].dist)
			{
				tmp = s->spr[k - 1];
				s->spr[k - 1] = s->spr[k];
				s->spr[k] = tmp;
			}
			k--;
		}
		i++;
	}
}

void		sprite_calculator(t_set *s)
{
	double	distance;
	int		i;

	i = 0;
	while (i < s->sp->count)
	{
		distance = ((s->pl.y - s->spr[i].x) * (s->pl.y - s->spr[i].x) +
			(s->pl.x - s->spr[i].y) * (s->pl.x - s->spr[i].y));
		s->spr[i].dist = distance;
		i++;
	}
	sort_sprites(s);
}

void		save_sprites(t_set *s)
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
				s->spr[n].x = i + 0.5;
				s->spr[n].y = k + 0.5;
				n++;
			}
			k++;
		}
		i++;
	}
}
