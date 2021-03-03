/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:08:38 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/03 17:47:16 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotateplayer(t_set *s, double rot)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = s->pl.dirx;
	s->pl.dirx = s->pl.dirx * cos(rot) - s->pl.diry * sin(rot);
	s->pl.diry = old_dir_x * sin(rot) + s->pl.diry * cos(rot);
	old_plane_x = s->pl.planex;
	s->pl.planex = s->pl.planex * cos(rot) - s->pl.planey * sin(rot);
	s->pl.planey = old_plane_x * sin(rot) + s->pl.planey * cos(rot);
}

static int	ch_colls(char c)
{
	if (c == '1' || c == '2')
		return (0);
	return (1);
}

static void	move_forth_back(t_set *s, int dir, double speed)
{
	if (ch_colls(s->map[(int)s->pl.y][(int)(s->pl.x + dir * s->pl.dirx *
		(speed + 0.3))]))
	{
		s->pl.x += dir * s->pl.dirx * speed;
	}
	if (ch_colls(s->map[(int)(s->pl.y + dir * s->pl.diry *
		(speed + 0.3))][(int)s->pl.x]))
	{
		s->pl.y += dir * s->pl.diry * speed;
	}
}

static void	move_sides(t_set *s, int dir, double speed)
{
	if (ch_colls(s->map[(int)s->pl.y][(int)(s->pl.x + -dir * s->pl.diry *
		(speed + 0.3))]))
	{
		s->pl.x += -dir * s->pl.diry * speed;
	}
	if (ch_colls(s->map[(int)(s->pl.y + dir * s->pl.dirx *
		(speed + 0.3))][(int)s->pl.x]))
	{
		s->pl.y += dir * s->pl.dirx * speed;
	}
}

void		moveplayer(t_set *s)
{
	double speed;

	speed = (s->size_x / (16000.0 / SPEED));
	if (s->pl.up)
		move_forth_back(s, 1, speed);
	if (s->pl.down)
		move_forth_back(s, -1, speed);
	if (s->pl.left)
		move_sides(s, -1, speed * 0.7);
	if (s->pl.right)
		move_sides(s, 1, speed * 0.7);
	if (s->pl.rrot)
		rotateplayer(s, speed / 2);
	if (s->pl.lrot)
		rotateplayer(s, -speed / 2);
}
