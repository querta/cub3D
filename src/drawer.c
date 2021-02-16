/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:12:38 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/16 18:43:40 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_vert_line(t_set *s, int x, double drawStart, double drawEnd, int color)
{
	// s->img->img = mlx_new_image(s->mlx->mlx, s->size_x, s->size_y);
	// s->img->addr = mlx_get_data_addr(s->img->img, &s->img->bits_per_pixel, &s->img->line_length, &s->img->endian);

	int i = 0;
	while (i < s->size_x)
	{
		if (i >= drawStart && i <= drawEnd)
		{
			// mlx_pixel_put(s->mlx->mlx, s->mlx->win, x, i, color);
			my_mlx_pixel_put(s->img, x, i, color);
		}
		i++;
	}
		// mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, s->img->img, 0, 0);

}

// double calculate_dist(t_set *s)
// {

// }

int draw_main(t_set *s)
{
	int x;
	x = 0;
	if(s->img->img)
		mlx_destroy_image(s->mlx->mlx, s->img->img);
	s->img->img = mlx_new_image(s->mlx->mlx, s->size_x, s->size_y);
	s->img->addr = mlx_get_data_addr(s->img->img, &s->img->bits_per_pixel, &s->img->line_length, &s->img->endian);
		while (x < (int)s->size_y)
		{
			//calculate ray position and direction
			double cameraX = 2 * x / (double)s->size_y - 1; //x-coordinate in camera space
			double rayDirX = s->pl.dirY + s->pl.planeY * cameraX;
			double rayDirY = s->pl.dirX + s->pl.planeX * cameraX;

				//which box of the map we're in
			int mapX = (int)s->pl.y;
			int mapY = (int)s->pl.x;

			//length of ray from current position to next x or y-side
			double sideDistX;
			double sideDistY;

			//length of ray from one x or y-side to next x or y-side
			double deltaDistX = fabs(1 / rayDirX);
			double deltaDistY = fabs(1 / rayDirY);
			double perpWallDist;

			//what direction to step in x or y-direction (either +1 or -1)
			int stepX;
			int stepY;

			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit?

			//calculate step and initial sideDist
			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (s->pl.y - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - s->pl.y) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (s->pl.x - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - s->pl.x) * deltaDistY;
			}
					//perform DDA

			while (s->map[mapX][mapY] != '1')
			{
				//jump to next map square, OR in x-direction, OR in y-direction
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				//Check if ray has hit a wall
				if (s->map[mapX][mapY] != '0') 
					hit = 1;
			} 

			if (side == 0) 
				perpWallDist = (mapX - s->pl.y + (1 - stepX) / 2) / rayDirX;
      		else
				perpWallDist = (mapY - s->pl.x + (1 - stepY) / 2) / rayDirY;


				//Calculate height of line to draw on screen
			int lineHeight = (int)(s->size_y / perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = -lineHeight / 2 + s->size_y / 2;
			if(drawStart < 0)drawStart = 0;
			int drawEnd = lineHeight / 2 + s->size_y / 2;
			if(drawEnd >= s->size_y)drawEnd = s->size_y - 1;
		
			//choose wall color
			int color;
			switch(s->map[mapX][mapY])
			{
			case 1:  color = 0xff0000; break; //red
			case 2:  color = 0x00ff00; break; //green
			case 3:  color = 0x0000ff; break; //blue
			case 4:  color = 0x000000; break; //white
			default: color = 0xffff00; break; //yellow
			}

			//give x and y sides different brightness
			if (side == 1) {color = color / 2;}

			//draw the pixels of the stripe as a vertical line
			// verLine(x, drawStart, drawEnd, color);
			// my_mlx_pixel_put(s->img, x, ray.y, color);

			// my_mlx_pixel_put(s->img, 10, 10, color);
			// printf("x=%d, drawStart=%d, drawEnd=%d\n", x, drawStart, drawEnd);
		// s->img->img = mlx_new_image(s->mlx->mlx, s->size_x, s->size_y);
		// s->img->addr = mlx_get_data_addr(s->img->img, &s->img->bits_per_pixel, &s->img->line_length, &s->img->endian);
			draw_vert_line(s, x, drawStart, drawEnd, color);
			x++;
		}
	mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, s->img->img, 0, 0);
	// printf("\n=================================================\n");
	return (1);
}