/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:32:59 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/08 15:42:16 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	void img_scale(t_point point, t_set *s, int color)
{
	t_point end;

	end.x = (point.x + 1) * SCALE;
	end.y = (point.y + 1) * SCALE;
	point.x *= SCALE;
	point.y *= SCALE;
	while (point.y < end.y)
	{
		while (point.x < end.x)
			my_mlx_pixel_put(s->img, point.x++, point.y, color);
		point.x -= SCALE;
		point.y++;
	}
}

static	void coords_change(t_set *s, char c, double speed)
{
	if (c == '+')
	{
		s->pl.y += sin(s->pl.dir) * speed;
		s->pl.x += cos(s->pl.dir) * speed;	
	}
	if (c == '-')
	{
		s->pl.y -= sin(s->pl.dir) * speed;
		s->pl.x -= cos(s->pl.dir) * speed;	
	}
}

// static	void coords_increase(t_set *s, double speed)
// {
// 	s->pl.y += sin(s->pl.dir) * speed;
// 	s->pl.x += cos(s->pl.dir) * speed;	
// }

// static	void coords_decrease(t_set *s, double speed)
// {
// 	s->pl.y -= sin(s->pl.dir) * speed;
// 	s->pl.x -= cos(s->pl.dir) * speed;	
// }

static	void	ray_processor(t_set *s)
{
	if (s->pl.up)
	{
		coords_change(s, '-', SPEED);
		if (s->map[(int)s->pl.y][(int)s->pl.x] == '1')
			coords_change(s, '+', SPEED);
	}
	if (s->pl.down)
	{
		coords_change(s, '+', SPEED);
		if (s->map[(int)s->pl.y][(int)s->pl.x] == '1')
			coords_change(s, '-', SPEED);
	}
	if (s->pl.left)
		s->pl.dir -= SPEED;
	if (s->pl.right)
		s->pl.dir += SPEED;
}

static	void	draw_rays(t_set *s)
{
	t_dpoint ray;
	double angle;
	
	angle = M_PI_4;
	if (s->mlx->img)
		mlx_destroy_image(s->mlx->mlx, s->mlx->img);
	while (angle >= -M_PI_4)
	{
		ray.x = s->pl.x * SCALE;
		ray.y = s->pl.y * SCALE;
		while(s->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
		{
				my_mlx_pixel_put(s->img, ray.x, ray.y, 0xff0000);
				ray.x -= cos(s->pl.dir + angle);
				ray.y -= sin(s->pl.dir + angle);
		}
		angle -= 0.001;
	}

}

int	draw_map(t_set *s)
{
	t_point point;

	if (s->mlx->img)
		mlx_destroy_image(s->mlx->mlx, s->mlx->img);
	s->img->img = mlx_new_image(s->mlx->mlx, s->size_x, s->size_y);
	s->img->addr = mlx_get_data_addr(s->img->img, &s->img->bits_per_pixel, &s->img->line_length, &s->img->endian);
	ft_bzero(&point, sizeof(t_point));
	while (s->map[point.y])
	{
		point.x = 0;
		while (s->map[point.y][point.x])
		{
			if (s->map[point.y][point.x] == '1')
				img_scale(point, s, 0xFFFFFF);
			point.x++;
		}
		point.y++;
	}
	ray_processor(s);
	draw_rays(s);
	mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, s->img->img, 0, 0);
	return (1);
}
