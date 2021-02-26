/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:12:38 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/26 21:00:29 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	void	collision_calculation(t_set *s, t_point *map)
{
	t_ray *r;

	r = s->ray;
	while (s->map[map->x][map->y] != '1')
	{
		if (s->map[map->x][map->y] == '2')
			sprite_calculator(s, map);
		if (r->sideDistX < r->sideDistY)
		{
			r->sideDistX += r->deltaDistX;
			map->x += r->stepX;
			r->side = 0;
		}
		else
		{
			r->sideDistY += r->deltaDistY;
			map->y += r->stepY;
			r->side = 1;
		}
	}
	if (r->side == 0)
		r->wall = (map->x - s->pl.y + (1 - r->stepX) / 2) / r->dirX;
	else
		r->wall = (map->y - s->pl.x + (1 - r->stepY) / 2) / r->dirY;
}

static	void	ray_calculation(t_set *s, t_point *map)
{
	s->ray->dirX = s->pl.dirY + s->pl.planeY * s->ray->cameraX;
	s->ray->dirY = s->pl.dirX + s->pl.planeX * s->ray->cameraX;
	s->ray->deltaDistX = fabs(1 / s->ray->dirX);
	s->ray->deltaDistY = fabs(1 / s->ray->dirY);
	if (s->ray->dirX < 0)
	{
		s->ray->stepX = -1;
		s->ray->sideDistX = (s->pl.y - map->x) * s->ray->deltaDistX;
	}
	else
	{
		s->ray->stepX = 1;
		s->ray->sideDistX = (map->x + 1.0 - s->pl.y) * s->ray->deltaDistX;
	}
	if (s->ray->dirY < 0)
	{
		s->ray->stepY = -1;
		s->ray->sideDistY = (s->pl.x - map->y) * s->ray->deltaDistY;
	}
	else
	{
		s->ray->stepY = 1;
		s->ray->sideDistY = (map->y + 1.0 - s->pl.x) * s->ray->deltaDistY;
	}
}

int				raycaster(t_set *s)
{
	int		x;
	t_point	map;
	// double buffer[s->size_x];
	// t_ray	ray;

	// s->ray->buffer = (double *)malloc(sizeof(double) * s->size_x);
	// s->ray = &ray;
	x = 0;
	image_refresh(s);
	while (x < (int)s->size_x)
	{
		map.x = (int)s->pl.y;
		map.y = (int)s->pl.x;
		s->ray->cameraX = 2 * x / (double)s->size_x - 1;
		ray_calculation(s, &map);
		collision_calculation(s, &map);
		draw_all(s, x);
		// buffer[x] = s->ray->wall;
		// s->ray->buffer = buffer;
		x++;
	}
	draw_sprites(s);
	if (s->save)
		save_screenshot(s);
	else if (!s->save)
	{	
		moveplayer(s);
		mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, s->img->img, 0, 0);
	}
	return (1);
}
