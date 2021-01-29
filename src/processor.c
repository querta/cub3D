/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:01:22 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/29 17:07:07 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
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
			mlx_pixel_put(set->mlx->mlx, set->mlx->win, point.x++, point.y, color);
		point.x -= SCALE;
		point.y++;
	}
}

void	draw_map(t_set *set)
{
	t_point point;

	ft_bzero(&point, sizeof(t_point));
	while (set->map[point.y])
	{
		point.x = 0;
		while (set->map[point.y][point.x])
		{
			if (set->map[point.y][point.x] == '1')
				img_scale(point, set, 0xFFFFFF);
			if (player_ch(set->map[point.y][point.x]))
				img_scale(point, set, 0x0000FF);
			point.x++;
		}
		point.y++;
	}
}

int			cube_start(t_set *s)
{
	t_data img;

	// printf("set-r:%s\nsize_x=%d, size_y=%d", set->r, set->size_x, set->size_y);
	s->mlx->mlx = mlx_init();

	s->mlx->win = mlx_new_window(s->mlx->mlx, s->size_x, s->size_y, "kek");
	img.img = mlx_new_image(s->mlx->mlx, s->size_x, s->size_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, img.img, 0, 0);
	// draw_map(s);
	mlx_loop(s->mlx->mlx);

	return (0);
}
