/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:08:38 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/26 14:23:34 by mmonte           ###   ########.fr       */
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

static	void	move_forth_back(t_set *s, int dir)
{
	if (s->map[(int)s->pl.y][(int)(s->pl.x + dir * s->pl.dirX * (SPEED + 0.3))] != '1')
		s->pl.x += dir * s->pl.dirX * SPEED;
	if (s->map[(int)(s->pl.y + dir * s->pl.dirY * (SPEED + 0.3))][(int)s->pl.x] != '1')
		s->pl.y += dir * s->pl.dirY * SPEED;
}

static	void	move_sides(t_set *s, int dir)
{
	if (s->map[(int)s->pl.y][(int)(s->pl.x + -dir * s->pl.dirY * (SPEED + 0.2))] != '1')
		s->pl.x += -dir * s->pl.dirY * SPEED;
	if (s->map[(int)(s->pl.y + dir * s->pl.dirX * (SPEED + 0.2))][(int)s->pl.x] != '1')
		s->pl.y += dir * s->pl.dirX * SPEED;
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
