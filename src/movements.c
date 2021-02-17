/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:08:38 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/17 21:13:19 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


static	void rotateplayer(t_set *s, double rotation)
{
	// dirY = sin(s->pl.dir) 
	// dirX=cos(dir)

	double oldDirX = s->pl.dirX;
	s->pl.dirX = s->pl.dirX * cos(rotation) - s->pl.dirY * sin(rotation);
	s->pl.dirY = oldDirX * sin(rotation) + s->pl.dirY * cos(rotation);
	s->pl.dir = cos(s->pl.dir) * acos(rotation) - sin(s->pl.dirY) * asin(rotation);
	double oldPlaneX = s->pl.planeX;
	s->pl.planeX = s->pl.planeX * cos(rotation) - s->pl.planeY * sin(rotation);
	s->pl.planeY = oldPlaneX * sin(rotation) + s->pl.planeY * cos(rotation);
		// printf("dirx=%f sinX=%f cosX=%f arcsinX=%f arccosX=%f diry=%f sinY=%f cosY=%f arcsinY=%f arccosY=%f side=%d\n", s->ray->dirX, sin(s->ray->dirX), cos(s->ray->dirX), asin(s->ray->dirX), acos(s->ray->dirX), s->ray->dirY, sin(s->ray->dirY), cos(s->ray->dirY), asin(s->ray->dirY), acos(s->ray->dirY), s->ray->side);	
		// printf("pl dirx=%f diry=%f  planeX=%f planeY=%f side=%d\n", s->pl.dirX, s->pl.dirY, s->pl.planeX, s->pl.planeY, s->ray->side);	
	// printf("pl dir=%f", s->pl.dir);
}

static	void move_forth_back(t_set *s, int dir)
{
	if (s->map[(int)s->pl.y][(int)(s->pl.x + dir * s->pl.dirX * SPEED)] != '1')
		s->pl.x += dir *s->pl.dirX * SPEED;
	if (s->map[(int)(s->pl.y + dir *s->pl.dirY * SPEED)][(int)s->pl.x] != '1')
		s->pl.y += dir *s->pl.dirY * SPEED;
}

void moveplayer(t_set *s)
{
    // double rotSpeed = SPEED / 1.5; 
				// printf("pl.x=%f, pl.y=%f, dirX=%f, dirY=%f, planeX=%f, planeY=%f\n", s->pl.x, s->pl.y, s->pl.dirX, s->pl.dirY, s->pl.planeX, s->pl.planeY);
// pl.x=13.100000, pl.y=4.100000, dirX=-1.000000, dirY=0.000000, planeX=0.000000, planeY=-0.660000
	if (s->pl.up)
		move_forth_back(s, 1);
	if (s->pl.down)
		move_forth_back(s, -1);
    if (s->pl.right)
		rotateplayer(s, SPEED * 2);
    if (s->pl.left)
		rotateplayer(s, -SPEED / 1.5);
}