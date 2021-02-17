/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:12:38 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/17 21:15:32 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int paintwall(t_set *s, int ray.side, t_point map)
// {
// 	int color;
// 	switch(s->map[map.x][map.y])
// 	{
// 		case 1:  color = 0xff0000; break; //red
// 		case 2:  color = 0x00ff00; break; //green
// 		case 3:  color = 0x0000ff; break; //blue
// 		case 4:  color = 0xffffff; break; //white
// 		default: color = 0xffff00; break; //yellow
// 	}

// 	//give x and y ray.sides different brightness
// 	if (ray.side == 1) {color = color / 2;}
// 	return(color);
// }

void	draw_walls(t_set *s, int x)
{	
	int lineHeight = (int)(s->size_y / s->ray->wall);
	int drawStart = -lineHeight / 2 + s->size_y / 2;
	if(drawStart < 0)drawStart = 0;
	int drawEnd = lineHeight / 2 + s->size_y / 2;
	if(drawEnd >= s->size_y)drawEnd = s->size_y - 1;
	int color;
	int i = 0;
	// int summ = s->ray->dirX + s->ray->dirX;

	// color = paintwall(s, ray.side, map);
	// printf("dirx=%f diry=%f deltaDistX=%f, deltaDistX=%f, sideDistX=%f, sideDistX=%f cameraX=%f cameraY=%f\n", s->ray->dirX, s->ray->dirY, s->ray->deltaDistX, s->ray->deltaDistY, s->ray->sideDistX, s->ray->sideDistY, s->ray->cameraX, s->ray->cameraY);	
	// if (s->ray->dirY > )
	if (acos(s->pl.dirX) == 0)
	{
		// if (s->ray->side)
		// 	color = 0xffff00;
		// else
			color = 0xff0000;
	}
	if (asin(s->pl.dirY) > 0)
	{
		// if (s->ray->side)
		// 	color = 0x00ffff;
		// else
			color = 0x0000ff;
	}
	while (i++ < s->size_y)
	{
		if (i >= drawStart && i <= drawEnd)
			my_mlx_pixel_put(s->img, x, i, color);
	}
}

// double calculate_dist(t_set *s)
// {

// }

int draw_main(t_set *s)
{
	int x;
	x = 0;
	t_point map;
	t_ray ray;

	s->ray = &ray;
	if(s->img->img)
		mlx_destroy_image(s->mlx->mlx, s->img->img);
	s->img->img = mlx_new_image(s->mlx->mlx, s->size_x, s->size_y);
	// printf("sizex=%d, sizey=%d \n", s->size_x, s->size_x);
	s->img->addr = mlx_get_data_addr(s->img->img, &s->img->bits_per_pixel, &s->img->line_length, &s->img->endian);
		while (x < (int)s->size_x)
		{
			//calculate ray position and direction
			ray.cameraX = 2 * x / (double)s->size_x - 1; //x-coordinate in camera space
			// dirY = sin(s->pl.dir) dirX=cos(dir)
			//
			//
			ray.dirX = s->pl.dirY + s->pl.planeY * ray.cameraX;
			ray.dirY = s->pl.dirX + s->pl.planeX * ray.cameraX;

				//which box of the map we're in
			map.x = (int)s->pl.y;
			map.y = (int)s->pl.x;

			//length of ray from current position to next x or y-ray.side

			//length of ray from one x or y-ray.side to next x or y-ray.side
			ray.deltaDistX = fabs(1 / ray.dirX);
			ray.deltaDistY = fabs(1 / ray.dirY);

			//what direction to step in x or y-direction (either +1 or -1)

			// int hit = 0; //was there a wall hit?

			//calculate step and initial ray.sideDist
			if (ray.dirX < 0)
			{
				ray.stepX = -1;
				ray.sideDistX = (s->pl.y - map.x) * ray.deltaDistX;
			}
			else
			{
				ray.stepX = 1;
				ray.sideDistX = (map.x + 1.0 - s->pl.y) * ray.deltaDistX;
			}
			if (ray.dirY < 0)
			{
				ray.stepY = -1;
				ray.sideDistY = (s->pl.x - map.y) * ray.deltaDistY;
			}
			else
			{
				ray.stepY = 1;
				ray.sideDistY = (map.y + 1.0 - s->pl.x) * ray.deltaDistY;
			}
			// raycalculator(s, map)
			while (s->map[map.x][map.y] != '1')
			{
				if (ray.sideDistX < ray.sideDistY)
				{
					ray.sideDistX += ray.deltaDistX;
					map.x += ray.stepX;
					ray.side = 0;
				}
				else
				{
					ray.sideDistY += ray.deltaDistY;
					map.y += ray.stepY;
					ray.side = 1;
				}
				// if (s->map[map.x][map.y] != '0') 
				// 	hit = 1;
			} 

			if (ray.side == 0) 
				ray.wall = (map.x - s->pl.y + (1 - ray.stepX) / 2) / ray.dirX;
      		else
				ray.wall = (map.y - s->pl.x + (1 - ray.stepY) / 2) / ray.dirY;

			draw_walls(s, x);
			x++;
		}
		printf("pl dir=%f, dirX=%f, dirY=%f, rayDirX=%f, rayDirY=%f\n", s->pl.dir, s->pl.dirX, s->pl.dirY, s->ray->dirX, s->ray->dirY);
		// printf("ra dir=%f, dirX=%f, dirY=%f, rayDirX=%f, rayDirY=%f\n", s->pl.dir, s->pl.dirX, s->pl.dirY, s->ray->dirX, s->ray->dirY);
		// printf("ra ", s->pl.dirX);

	moveplayer(s);
	mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, s->img->img, 0, 0);
	return (1);
}