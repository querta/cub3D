/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:29:13 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/08 15:37:12 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void            my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             keypress(int keycode, t_set *s)
{
	double coords;

	coords = (double)SPEED / 100;
	mlx_clear_window(s->mlx->mlx, s->mlx->win);
	
	if (keycode == 53)
		error(s, 0);
	if (keycode == 13 || keycode == 126)	// up
		s->pl.up = 1;
	if (keycode == 1 || keycode == 125)		// down
		s->pl.down = 1;
	if (keycode == 0 || keycode == 123)		// left
		s->pl.left = 1;
	if (keycode == 2 || keycode == 124)		//right
		s->pl.right = 1;
	draw_map(s);

	return (0);
}

int             keyrelease(int keycode, t_set *s)
{
	double coords;

	coords = (double)SPEED / 100;
	mlx_clear_window(s->mlx->mlx, s->mlx->win);
	
	if (keycode == 13 || keycode == 126)	// up
		s->pl.up = 0;
	if (keycode == 1 || keycode == 125)		// down
		s->pl.down = 0;
	if (keycode == 0 || keycode == 123)		// left
		s->pl.left = 0;
	if (keycode == 2 || keycode == 124)		//right
		s->pl.right = 0;
	draw_map(s);

	return (0);
}

int closewin(t_set *s)
{
	error(s, SUCCESS);
	return (1);
}

void	create_mlx(t_set *s)
{
	t_img img;
	int max_height;
	int max_width;

	s->mlx->mlx = mlx_init();
	s->img = &img;
	mlx_get_screen_size(s->mlx->mlx, &max_width, &max_height);
	if (s->size_x > max_width)
		s->size_x = max_width;
	if (s->size_y > max_height)
		s->size_y = max_height;
	if (s->size_x < 640)
		s->size_x = 640;
	if (s->size_y < 640)
		s->size_y = 640;
	s->mlx->win = mlx_new_window(s->mlx->mlx, s->size_x, s->size_y, "kek");
}