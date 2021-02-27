/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:08:38 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/27 15:27:59 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	void	rotateplayer(t_set *s, double rot)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = s->pl.dirX;
	s->pl.dirX = s->pl.dirX * cos(rot) - s->pl.dirY * sin(rot);
	s->pl.dirY = old_dir_x * sin(rot) + s->pl.dirY * cos(rot);
	old_plane_x = s->pl.planeX;
	s->pl.planeX = s->pl.planeX * cos(rot) - s->pl.planeY * sin(rot);
	s->pl.planeY = old_plane_x * sin(rot) + s->pl.planeY * cos(rot);
}

int ch_colls(char c)
{
	if (c == '1' || c == '2')
		return (0);
	return (1);
}

static	void	move_forth_back(t_set *s, int dir, double speed)
{
	if (ch_colls(s->map[(int)s->pl.y][(int)(s->pl.x + dir * s->pl.dirX * (speed + 0.3))]))
		s->pl.x += dir * s->pl.dirX * speed;
	if (ch_colls(s->map[(int)(s->pl.y + dir * s->pl.dirY * (speed + 0.3))][(int)s->pl.x]))
		s->pl.y += dir * s->pl.dirY * speed;
}

static	void	move_sides(t_set *s, int dir, double speed)
{
	if (ch_colls(s->map[(int)s->pl.y][(int)(s->pl.x + -dir * s->pl.dirY * (speed + 0.3))]))
		s->pl.x += -dir * s->pl.dirY * speed;
	if (ch_colls(s->map[(int)(s->pl.y + dir * s->pl.dirX * (speed + 0.3))][(int)s->pl.x]))
		s->pl.y += dir * s->pl.dirX * speed;
}

void			moveplayer(t_set *s)
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
