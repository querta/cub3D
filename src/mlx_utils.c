/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:29:13 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/25 14:03:26 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	image_refresh(t_set *s)
{
	if (s->img->img && !s->save)
		mlx_destroy_image(s->mlx->mlx, s->img->img);
	s->img->img = mlx_new_image(s->mlx->mlx, s->size_x, s->size_y);
	s->img->addr = mlx_get_data_addr(s->img->img,
			&s->img->bits_per_pixel, &s->img->line_length, &s->img->endian);
}

void create_teximg(t_set *s, t_img *img)
{
	if (!(img->img = mlx_xpm_file_to_image(s->mlx->mlx, img->path, &s->tex->wi, &s->tex->he)))
		error(s, ER_TEXTURE);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void	create_textures(t_set *s)
{

	create_teximg(s, s->tex->no);
	create_teximg(s, s->tex->so);
	create_teximg(s, s->tex->we);
	create_teximg(s, s->tex->ea);

}

void	create_mlx(t_set *s)
{
	int		max_height;
	int		max_width;

	s->mlx->mlx = mlx_init();
	if (!s->save)
	{
		mlx_get_screen_size(s->mlx->mlx, &max_width, &max_height);
		s->size_x = (s->size_x > max_width) ? max_width : s->size_x;
		s->size_y = (s->size_y > max_height) ? max_height : s->size_y;
		s->size_x = (s->size_x < 640) ? 640 : s->size_x;
		s->size_y = (s->size_y < 640) ? 640 : s->size_y;
		s->mlx->win = mlx_new_window(s->mlx->mlx, s->size_x, s->size_y, "kek");
	}
	else if (s->save)
	{
		s->size_x = 640;
		s->size_y = 640;
	}
	create_textures(s);
}
