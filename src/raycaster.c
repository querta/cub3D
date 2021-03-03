/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:12:38 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/03 17:52:12 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	collision_calculation(t_set *s, t_point *map)
{
	t_ray *r;

	r = s->ray;
	while (s->map[map->x][map->y] != '1')
	{
		if (s->map[map->x][map->y] == '2')
			sprite_calculator(s);
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			map->x += r->stepx;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			map->y += r->stepy;
			r->side = 1;
		}
	}
	if (r->side == 0)
		r->wall = (map->x - s->pl.y + (1 - r->stepx) / 2) / r->dirx;
	else
		r->wall = (map->y - s->pl.x + (1 - r->stepy) / 2) / r->diry;
}

static	void	ray_calculation(t_set *s, t_point *map)
{
	s->ray->dirx = s->pl.diry + s->pl.planey * s->ray->cam_x;
	s->ray->diry = s->pl.dirx + s->pl.planex * s->ray->cam_x;
	s->ray->delta_dist_x = fabs(1 / s->ray->dirx);
	s->ray->delta_dist_y = fabs(1 / s->ray->diry);
	if (s->ray->dirx < 0)
	{
		s->ray->stepx = -1;
		s->ray->side_dist_x = (s->pl.y - map->x) * s->ray->delta_dist_x;
	}
	else
	{
		s->ray->stepx = 1;
		s->ray->side_dist_x = (map->x + 1.0 - s->pl.y) * s->ray->delta_dist_x;
	}
	if (s->ray->diry < 0)
	{
		s->ray->stepy = -1;
		s->ray->side_dist_y = (s->pl.x - map->y) * s->ray->delta_dist_y;
	}
	else
	{
		s->ray->stepy = 1;
		s->ray->side_dist_y = (map->y + 1.0 - s->pl.x) * s->ray->delta_dist_y;
	}
}

static void		calculate_lines(t_set *s, t_point *map)
{
	int x;

	x = 0;
	while (x < (int)s->size_x)
	{
		map->x = (int)s->pl.y;
		map->y = (int)s->pl.x;
		s->ray->cam_x = 2 * x / (double)s->size_x - 1;
		ray_calculation(s, map);
		collision_calculation(s, map);
		draw_all(s, x);
		s->ray->buffer[x] = s->ray->wall;
		x++;
	}
}

int				raycaster(t_set *s)
{
	t_point	map;

	s->ray->buffer = (double *)ft_calloc(s->size_x, sizeof(double));
	image_refresh(s);
	calculate_lines(s, &map);
	draw_sprites(s);
	free(s->ray->buffer);
	if (s->save)
		save_screenshot(s);
	else if (!s->save)
	{
		moveplayer(s);
		mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, s->img->img, 0, 0);
	}
	return (1);
}
