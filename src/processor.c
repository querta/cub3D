/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:01:22 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/26 21:06:36 by mmonte           ###   ########.fr       */
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

// TODO: сделать нормальное масштабирование

void	draw_map(char **map, void	*mlx, void	*mlx_win)
{
	int		x = 5;
	// int		y = 5;
	int		i;
	int		k;
	
	i = 0;
	k = 0;
	(void)map;
	while(map[k])
	{
		i = 0;
		while(map[i])
		{
			if (map[i][k] == '1')
				mlx_pixel_put(mlx, mlx_win, k, i, 0xFFFFFF);
			i++;
		}
		k++;
	}
	
	// while (y++ < 106)
	// {
	// 	x = 100;
	// 	while(x++ < 106)
	// 		mlx_pixel_put(mlx, mlx_win, x, y, 0xFFFFFF);
	// }
}

int			cube_start(t_set *set, char **map)
{
	void	*mlx;
	void	*mlx_win;
    // t_data  img;

	
	(void)set;
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
	draw_map(map, mlx, mlx_win);
	mlx_loop(mlx);
	// printf("line_lengh:%d bpp:%d", img.line_length,	img.bits_per_pixel);

	return (0);
}
