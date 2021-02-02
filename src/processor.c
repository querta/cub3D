/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:01:22 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/02 16:38:10 by mmonte           ###   ########.fr       */
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


void img_scale(t_point point, t_set *set, int color)
{
	t_point end;

	end.x = (point.x + 1) * SCALE;
	end.y = (point.y + 1) * SCALE;
	point.x *= SCALE;
	point.y *= SCALE;
	while (point.y < end.y)
	{
		while (point.x < end.x)
			my_mlx_pixel_put(set->img, point.x++, point.y, color);
		point.x -= SCALE;
		point.y++;
	}
}

/* перенести парсинг игрока в другое место
убрать отсюда отрисовку позиции игрока, сделать для этого отдельную функцию */

void	draw_map(t_set *s)
{
	t_point point;

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
			if (player_ch(s->map[point.y][point.x]))
			{
				s->pl.x = point.x;
				s->pl.y = point.y;
				s->pl.pos = s->map[point.y][point.x];
				img_scale(point, s, 0x0000FF);
			}
			point.x++;
		}
		point.y++;
	}

	draw_player(s); 
	mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, s->img->img, 0, 0);
	mlx_destroy_image(s->mlx->mlx, s->mlx->img);
}

int             winactions(int keycode, t_set *s)
{
	mlx_clear_window(s->mlx->mlx, s->mlx->win);
	// mlx_destroy_image(s->mlx->mlx, s->mlx->img);
	if (keycode == 53)
   		mlx_destroy_window(s->mlx->mlx, s->mlx->win);
	if (keycode == 13 || keycode == 126)
	{
		s->map[s->pl.y][s->pl.x] = '0';
		s->map[6][s->pl.x] = s->pl.pos;
	}
	// printf("keycode=%d\n", keycode);
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

	// printf("do izm 11\n%s:\n", s->map[11]);
	// printf("do izm 6\n%s:\n", s->map[6]);
	// s->map[11][26] = '0';
	// s->map[6][26] = 'N';
	// printf("posle izm11\n%s:\n", s->map[11]);
	// printf("posle izm6\n%s:\n", s->map[6]);
	// printf("set-r:%s\nsize_x=%d, size_y=%d", set->r, set->size_x, set->size_y);
	s->mlx->mlx = mlx_init();

	s->mlx->win = mlx_new_window(s->mlx->mlx, s->size_x, s->size_y, "kek");
	// s->img->img = mlx_new_image(s->mlx->mlx, s->size_x, s->size_y);
	// s->img->addr = mlx_get_data_addr(s->img->img, &s->img->bits_per_pixel, &s->img->line_length, &s->img->endian);
	
	draw_map(s);
	mlx_hook(s->mlx->win, 2, 1L<<0, winactions, s);

	// mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, s->img->img, 0, 0);
	// mlx_destroy_image(s->mlx->mlx, s->mlx->img);
	// printf("pos=%c, map 6-%d:%c\n", s->map[s->pl.y][s->pl.x], s->pl.y, s->map[6][s->pl.x]);
	// printf("pl.x:%d pl.y:%d, map:%s\n", s->pl.x, s->pl.y, s->map[s->pl.y]);
	// s->map[s->pl.y][s->pl.x] = '0';
	// s->map[6][s->pl.x] = s->pl.pos;
	// sleep(5);
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