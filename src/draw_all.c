/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:50:58 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/03 18:13:01 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			paint_walls(t_set *s)
{
	int color;

	if (s->ray->side == 1)
	{
		if (s->ray->diry > 0)
			color = (*(int *)(s->tex->we->addr +
			(s->tex->y * s->tex->we->line_length + s->tex->x *
			(s->tex->we->bits_per_pixel / 8))));
		else
			color = (*(int *)(s->tex->ea->addr +
			(s->tex->y * s->tex->ea->line_length + s->tex->x *
			(s->tex->ea->bits_per_pixel / 8))));
	}
	if (s->ray->side == 0)
	{
		if (s->ray->dirx > 0)
			color = (*(int *)(s->tex->so->addr +
			(s->tex->y * s->tex->so->line_length + s->tex->x *
			(s->tex->so->bits_per_pixel / 8))));
		else
			color = (*(int *)(s->tex->no->addr +
			(s->tex->y * s->tex->no->line_length + s->tex->x *
			(s->tex->no->bits_per_pixel / 8))));
	}
	return (color);
}

static void	draw_vert(t_set *s, int x, int drawstart, int drawend)
{
	int i;
	int color;

	i = 0;
	while (i < s->size_y)
	{
		if (i < drawstart)
			color = s->c;
		else if (i >= drawstart && i <= drawend)
		{
			s->tex->y = (int)s->tex->pos & (s->tex->he - 1);
			s->tex->pos += s->tex->step;
			color = paint_walls(s);
		}
		else if (i > drawend)
			color = s->f;
		my_mlx_pixel_put(s->img, x, i, color);
		i++;
	}
}

static void	calculate_textures(t_set *s, int x)
{
	int line_height;
	int drawstart;
	int drawend;

	line_height = (int)(s->size_y / s->ray->wall);
	drawstart = -line_height / 2 + s->size_y / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = line_height / 2 + s->size_y / 2;
	if (drawend >= s->size_y)
		drawend = s->size_y - 1;
	s->tex->step = 1.0 * s->tex->he / line_height;
	s->tex->pos = (drawstart - s->size_y / 2 + line_height / 2) * s->tex->step;
	draw_vert(s, x, drawstart, drawend);
}

static void	get_texsize(t_set *s)
{
	if (s->ray->side == 1 && s->ray->diry > 0)
	{
		s->tex->wi = s->tex->we->wi;
		s->tex->he = s->tex->we->he;
	}
	if (s->ray->side == 1 && s->ray->diry <= 0)
	{
		s->tex->wi = s->tex->ea->wi;
		s->tex->he = s->tex->ea->he;
	}
	if (s->ray->side == 0 && s->ray->diry > 0)
	{
		s->tex->wi = s->tex->so->wi;
		s->tex->he = s->tex->so->he;
	}
	if (s->ray->side == 0 && s->ray->diry <= 0)
	{
		s->tex->wi = s->tex->no->wi;
		s->tex->he = s->tex->no->he;
	}
}

void		draw_all(t_set *s, int x)
{
	s->tex->wallx = 0;
	if (s->ray->side == 0)
		s->tex->wallx = s->pl.x + s->ray->wall * s->ray->diry;
	else
		s->tex->wallx = s->pl.y + s->ray->wall * s->ray->dirx;
	s->tex->wallx -= floor((s->tex->wallx));
	get_texsize(s);
	s->tex->x = (int)(s->tex->wallx * (double)s->tex->wi);
	if (s->ray->side == 0 && s->ray->dirx > 0)
		s->tex->x = s->tex->wi - s->tex->x - 1;
	if (s->ray->side == 1 && s->ray->diry < 0)
		s->tex->x = s->tex->wi - s->tex->x - 1;
	calculate_textures(s, x);
}
