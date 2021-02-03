/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:01:22 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/03 18:39:30 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#include <unistd.h>

typedef struct  s_vars {
        void    *mlx;
        void    *win;
}               t_vars;


void            my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


void img_scale(t_point point, t_set *s, int color)
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

/* сделать лучи! */

void	draw_player(t_set *s)
{
	t_dpoint point;
	t_dpoint end;
	double coords;
	
	coords = (double)SPEED / 100;
	if (s->mlx->img)
		mlx_destroy_image(s->mlx->mlx, s->mlx->img);
	ft_bzero(&point, sizeof(t_point));
	if (s->pl.up)
		s->pl.y -= coords;
	if (s->pl.down)
		s->pl.y += coords;
	if (s->pl.left)
		s->pl.x -= coords;
	if (s->pl.right)
		s->pl.x += coords;
	point.x = s->pl.x;
	point.y = s->pl.y;
	end.x = (point.x + 1) * SCALE;
	end.y = (point.y + 1) * SCALE;
	point.x *= SCALE;
	point.y *= SCALE;
	while (point.y < end.y)
	{
		while (point.x < end.x)
			my_mlx_pixel_put(s->img, point.x++, point.y, 0x0000FF);
		point.x -= SCALE;
		point.y++;
	}
	// point.x = (float)s->pl.x;
	// point.y = (float)s->pl.y;
	// img_scale(point, s, 0x0000FF);

}

void	draw_map(t_set *s)
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
			// if (player_ch(s->map[point.y][point.x]))
			// {
			// 	s->pl.x = point.x;
			// 	s->pl.y = point.y;
			// 	s->pl.pos = s->map[point.y][point.x];
			// 	img_scale(point, s, 0x0000FF);
			// }
			point.x++;
		}
		point.y++;
	}
	draw_player(s); 
	mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, s->img->img, 0, 0);
	// mlx_destroy_image(s->mlx->mlx, s->mlx->img);
}

/* 
up = 126
down = 125
left =	123
right = 124

w = 13
s =	1
a = 0
d = 2
 */

int             keypress(int keycode, t_set *s)
{
	double coords;

	coords = (double)SPEED / 100;
	mlx_clear_window(s->mlx->mlx, s->mlx->win);
	
	if (keycode == 53)
	{
   		mlx_destroy_window(s->mlx->mlx, s->mlx->win);
		return (0);
	}
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

int			cube_start(t_set *s)
{
	t_img img;
	// t_vars    vars;

	s->img = &img;
	int i = 0;
	while (s->map[++i])
		ft_putendl_fd(s->map[i], 1);

	s->mlx->mlx = mlx_init();
	s->mlx->win = mlx_new_window(s->mlx->mlx, s->size_x, s->size_y, "kek");
	// s->img->img = mlx_new_image(s->mlx->mlx, s->size_x, s->size_y);
	// s->img->addr = mlx_get_data_addr(s->img->img, &s->img->bits_per_pixel, &s->img->line_length, &s->img->endian);
	
	draw_map(s);
	mlx_hook(s->mlx->win, 2, 1L<<0, keypress, s);
	mlx_hook(s->mlx->win, 3, 1L<<1, keyrelease, s);
	mlx_loop(s->mlx->mlx);

	return (0);
}

/* 
up = 126
down = 125
left =	123
right = 124

w = 13
s =	1
a = 0
d = 2
 */