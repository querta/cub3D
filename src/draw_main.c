/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:50:58 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/19 13:39:47 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	int paint_walls(t_set *s)
{
	int color;
	if (s->ray->side == 1) // E W
	{
		if (s->ray->dirY > 0)
			color = 0x00ffff;	// W
		else
			color = 0x0000ff; // E
	}
	if (s->ray->side == 0) // N S
		{
		if (s->ray->dirX > 0)  // S
			color = 0xffff00;
		else
			color = 0xff0000;	// N
	}
	return (color);
}

void text_reder(s_tex *tex)
{
	
}

void	draw_all(t_set *s, int x)
{	
	int lineHeight;
	int drawStart;
	int drawEnd;
	int color;
	int i;

	lineHeight = (int)(s->size_y / s->ray->wall);
	drawStart = -lineHeight / 2 + s->size_y / 2;
	if(drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + s->size_y / 2;
	if(drawEnd >= s->size_y)
		drawEnd = s->size_y - 1;
	i = 0;
	color = paint_walls(s);

	t_img texture;
	int img_width;
	int img_height;
	char *relative_path = "./textures/eagle.xpm";
	texture.img = mlx_xpm_file_to_image(s->mlx->mlx, relative_path, &img_width, &img_height);
	texture.addr = mlx_get_data_addr(texture.img, &texture.bits_per_pixel, &texture.line_length, &texture.endian);
	// printf("two\n");

	double wallX; //where exactly the wall was hit
	if (s->ray->side == 0) wallX = s->pl.y + s->ray->wall * s->ray->dirY;
	else
		wallX = s->pl.x + s->ray->wall * s->ray->dirX;
	wallX -= floor((wallX));
	int texX = (int)wallX * (double)img_width;
	if(s->ray->side == 0 && s->ray->dirX > 0) 
		texX = img_width - texX - 1;
	if(s->ray->side == 1 && s->ray->dirY < 0) 
		texX = img_width - texX - 1;
	double step = 1.0 * img_height / lineHeight;
	double texPos = (drawStart - s->size_y / 2 + lineHeight / 2) * step;

// (*(int *)(texture->addr + (w->tex[1] * texture->line_length + w->tex[0] * (texture->bits_per_pixel / 8))))
// 		  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// s->img->img = mlx_xpm_file_to_image(s->mlx->mlx, "../textures/wood.xpm", &img_width, &img_height);
// printf("img=%p, addr=%p, bpp=%d, endian=%d\n", texture->img, texture.addr, texture.bits_per_pixel, texture.endian);
	while (i < s->size_y)
	{
		if (i < drawStart)
			my_mlx_pixel_put(s->img, x, i, 0x99ffff);
		else if (i >= drawStart && i <= drawEnd)
		{
			int texY = (int)texPos & (img_height - 1);
			texPos += step;
			color = (*(int *)(texture.addr + (texY * texture.line_length + texX * (texture.bits_per_pixel / 8))));
			my_mlx_pixel_put(s->img, x, i, color);
		}
		else if (i > drawEnd)
			my_mlx_pixel_put(s->img, x, i, 0x997777);
		i++;
	}
}
