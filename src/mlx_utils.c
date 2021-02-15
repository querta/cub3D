/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:29:13 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/15 14:56:54 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void            my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	create_mlx(t_set *s)
{
	t_img img;
	int max_height;
	int max_width;

	// ft_bzero(&img, sizeof(img));
	s->mlx->mlx = mlx_init();
	s->img = &img;
	mlx_get_screen_size(s->mlx->mlx, &max_width, &max_height);
	s->size_x = (s->size_x > max_width) ? max_width : s->size_x;
	s->size_y = (s->size_x > max_height) ? max_height : s->size_y;
	s->size_x = (s->size_x < 640) ? 640 : s->size_x;
	s->size_y = (s->size_x < 640) ? 640 : s->size_y;
	// if (s->size_x > max_width)
	// 	s->size_x = max_width;
	// if (s->size_y > max_height)
	// 	s->size_y = max_height;
	// if (s->size_x < 640)
	// 	s->size_x = 640;
	// if (s->size_y < 640)
	// 	s->size_y = 640;
	s->mlx->win = mlx_new_window(s->mlx->mlx, s->size_x, s->size_y, "kek");

	// s->img->img = mlx_new_image(s->mlx->mlx, s->size_x, s->size_y);
	// s->img->addr = mlx_get_data_addr(s->img->img, &s->img->bits_per_pixel, &s->img->line_length, &s->img->endian);
}
