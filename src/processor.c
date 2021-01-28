/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:01:22 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/28 18:12:37 by mmonte           ###   ########.fr       */
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

typedef struct s_point {
	int x;
	int y;
}			t_point;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

// TODO: сделать нормальное масштабирование

void img_scale(t_point point, void	*mlx, void	*mlx_win)
{
	t_point end;

	end.x = (point.x + 1) * SCALE;
	end.y = (point.y + 1) * SCALE;
	point.x *= SCALE;
	point.y *= SCALE;
	while (point.y < end.y)
	{
		while (point.x < end.x)
			mlx_pixel_put(mlx, mlx_win, point.x++, point.y, 0xFFFFFF);
		point.x -= SCALE;
		point.y++;
	}
}

void	draw_map(t_set *set, void	*mlx, void	*mlx_win)
{
	t_point point;

	ft_bzero(&point, sizeof(t_point));
	while (set->map[point.y])
	{
		point.x = 0;
		while (set->map[point.y][point.x])
		{
			if (set->map[point.y][point.x] == '1')
				img_scale(point, mlx, mlx_win);
			point.x++;
		}
		point.y++;
	}
	
	// int		x = 5;
	// int		y = 5;
	// int		i;
	// int		k;
	
	// i = 0;
	// k = 0;
	// while(set->map[k])
	// {
	// 	i = 0;
	// 	while(set->map[i])
	// 	{
	// 		if (set->map[i][k] == '1')
	// 			mlx_pixel_put(mlx, mlx_win, k, i, 0xFFFFFF);
	// 		i++;
	// 	}
	// 	k++;
	// }
	// while(k < 640)
	// {
	// 	i = 0;
	// 	while(i < 640)
	// 	{
	// 		if (set->map[i / SCALE][k / SCALE] == '1')
	// 			mlx_pixel_put(mlx, mlx_win, i, k, 0xFFFFFF);
	// 		i++;
	// 	}
	// 	k++;
	// }
	
	// while (y++ < 106)
	// {
	// 	x = 100;
	// 	while(x++ < 106)
	// 		mlx_pixel_put(mlx, mlx_win, x, y, 0xFFFFFF);
	// }

}

int			cube_start(t_set *set)
{
	void	*mlx;
	void	*mlx_win;
    // t_data  img;

	
	// printf("set-r:%s\nsize_x=%d, size_y=%d", set->r, set->size_x, set->size_y);
	mlx = mlx_init();
    // img = mlx_new_image(mlx, 1920, 1080);

	mlx_win = mlx_new_window(mlx, set->size_x, set->size_y, "kek");
	// img.img = mlx_new_image(mlx, 1920, 1080);
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
    //                              &img.endian);

    // my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
    // mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	// mlx_pixel_put (mlx, mlx_win, 100, 100, 0x00FF0000);
	draw_map(set, mlx, mlx_win);
	mlx_loop(mlx);
	// printf("line_lengh:%d bpp:%d", img.line_length,	img.bits_per_pixel);

	return (0);
}
