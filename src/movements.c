/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:08:38 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/19 16:17:49 by mmonte           ###   ########.fr       */
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
	s->pl.dir = cos(s->pl.dir) * acos(rot) - sin(s->pl.dirY) * asin(rot);
	old_plane_x = s->pl.planeX;
	s->pl.planeX = s->pl.planeX * cos(rot) - s->pl.planeY * sin(rot);
	s->pl.planeY = old_plane_x * sin(rot) + s->pl.planeY * cos(rot);
}

static	void	move_forth_back(t_set *s, int dir)
{
	if (s->map[(int)s->pl.y][(int)(s->pl.x + dir * s->pl.dirX * SPEED)] != '1')
		s->pl.x += dir * s->pl.dirX * SPEED;
	if (s->map[(int)(s->pl.y + dir * s->pl.dirY * SPEED)][(int)s->pl.x] != '1')
		s->pl.y += dir * s->pl.dirY * SPEED;
}

static	void	move_sides(t_set *s, int dir)
{
	// if (asin(s->pl.dirY) < M_2_PI/3)
	// 	dir *= -1;
	// N и S - X меняется Y нет dirx=0, diry=-1 и diry = 1 если S
	if (s->map[(int)s->pl.y][(int)(s->pl.x + dir * s->pl.dirX * SPEED)] != '1')
		s->pl.x -= dir * sin(s->pl.dirY) * SPEED;
	if (s->map[(int)(s->pl.y + dir * s->pl.dirY * SPEED)][(int)s->pl.x] != '1')
		s->pl.y -= dir * cos(s->pl.dirX) * SPEED;
	printf("x=%f y=%f dirX=%f, dirY=%f\n", s->pl.x, s->pl.y, s->pl.dirX, s->pl.dirY);
}

void			moveplayer(t_set *s)
{
	if (s->pl.up)
		move_forth_back(s, 1);
	if (s->pl.down)
		move_forth_back(s, -1);
	if (s->pl.left)
		move_sides(s, -1);
	if (s->pl.right)
		move_sides(s, 1);
	if (s->pl.rrot)
		rotateplayer(s, SPEED / 1.5);
	if (s->pl.lrot)
		rotateplayer(s, -SPEED / 1.5);
}
