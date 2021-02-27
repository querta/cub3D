/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:07:20 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/27 21:09:19 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void draw_vert(t_set *s, int stripe, int start_y, int end_y)
{
	int y;

	y = start_y;
	s->tex->x = (int)(256 * (stripe - (-s->sp->width / 2 + s->sp->screen_x)) * s->tex->spr->wi / s->sp->width) / 256;
			if (s->sp->transform_y > 0 && stripe > 0 && stripe < s->size_x && s->sp->transform_y < s->ray->buffer[stripe])
			{
				while (y < end_y)
				{
					int d = (y)*256 - s->size_y * 128 + s->sp->height * 128;
					s->tex->y = ((d * s->tex->spr->he) / s->sp->height) / 256;
					int color = (*(int *)(s->tex->spr->addr + (s->tex->y * s->tex->spr->line_length + s->tex->x * (s->tex->spr->bits_per_pixel / 8))));
						if (color > 0)
							my_mlx_pixel_put(s->img, stripe, y, color);
				y++;
				}
			}
}

static void	draw(t_set *s, int start_x, int end_x)
{
	int stripe;
		int start_y;
	int end_y;

		start_y = -s->sp->height / 2 + s->size_y / 2;
		if (start_y < 0)
			start_y = 0;
		end_y = s->sp->height / 2 + s->size_y / 2;
		if (end_y >= s->size_y)
			end_y = s->size_y - 1;
	stripe = start_x;
	while (stripe < end_x)
	{
		draw_vert(s, stripe, start_y, end_y);
		stripe++;
	}
}

static void calculate_hewi(t_set *s)
{

	int start_x;
	int end_x;

		//calculate width of the sprite
		s->sp->width = fabs((double)(s->size_x / s->sp->transform_y));
		start_x = -s->sp->width / 2 + s->sp->screen_x;
		if (start_x < 0)
			start_x = 0;
		end_x = s->sp->width / 2 + s->sp->screen_x;
		if (end_x >= s->size_x)
			end_x = s->size_x - 1;
		draw(s, start_x, end_x);
}

void draw_sprites(t_set *s)
{
	int i;

	i = 0;
	while (i < s->sp->count)
	{
		s->sp->x = s->spr[i].x - s->pl.y;
		s->sp->y = s->spr[i].y - s->pl.x;
		s->sp->coef = 1.0 / (s->pl.planeY * s->pl.dirX - s->pl.dirY * s->pl.planeX);
		s->sp->transform_x = s->sp->coef * (s->pl.dirX * s->sp->x - s->pl.dirY * s->sp->y);
		s->sp->transform_y = s->sp->coef * (-s->pl.planeX * s->sp->x + s->pl.planeY * s->sp->y);
		s->sp->screen_x = (int)((s->size_x / 2) * (1 + s->sp->transform_x / s->sp->transform_y));
		s->sp->height = fabs((double)(s->size_y / s->sp->transform_y)); 
		calculate_hewi(s);
		i++;
	}
}