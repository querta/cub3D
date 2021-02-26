/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:07:20 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/26 21:02:56 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_sprites(t_set *s)
{
	// int i;

	// i = 0;
    for(int i = 0; i < s->sprites; i++)
    {
      //translate sprite position to relative to camera
      double spriteX = s->spr[0].x - s->pl.y;
      double spriteY = s->spr[0].y - s->pl.x;

      double invDet = 1.0 / (s->pl.planeX * s->pl.dirY - s->pl.dirX * s->pl.planeY); //required for correct matrix multiplication

      double transformX = invDet * (s->pl.dirY * spriteX - s->pl.dirX * spriteY);
      double transformY = invDet * (-s->pl.planeY * spriteX + s->pl.planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

      int spriteScreenX = (int)((s->size_x / 2) * (1 + transformX / transformY));

      //calculate height of the sprite on screen
      int spriteHeight = abs((int)(s->size_y / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
      //calculate lowest and highest pixel to fill in current stripe
      int drawStartY = -spriteHeight / 2 + s->size_y / 2;
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 + s->size_y / 2;
      if(drawEndY >= s->size_y) drawEndY = s->size_y - 1;

      //calculate width of the sprite
      int spriteWidth = abs((int)(s->size_y / (transformY)));
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= s->size_x) drawEndX = s->size_x - 1;

      //loop through every vertical stripe of the sprite on screen
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        s->tex->x = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * s->tex->spr->wi / spriteWidth) / 256;
// if(transformY > 0 && stripe > 0 && stripe < s->size_x && transformY < s->ray->buffer[stripe])
        for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
        {
			int d = (y) * 256 - s->size_y * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
			s->tex->y = ((d * s->tex->spr->he) / spriteHeight) / 256;
			int color = (*(int *)(s->tex->spr->addr + (s->tex->y * s->tex->spr->line_length + s->tex->x * (s->tex->spr->bits_per_pixel / 8))));
        //   if((color & 0x00FFFFFF) != 0) buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
			// printf("addr=%s, y=%d, y=%d\n", s->tex->spr->addr, s->tex->y, s->tex->x );
			if (color != 0)
			{
				// printf("i=%d, y=%d, color=%x\n", i, y, color);
				// mlx_pixel_put(s->mlx->mlx, s->mlx->win, i, y, color);
				my_mlx_pixel_put(s->img, i, y, color);
						mlx_put_image_to_window(s->mlx->mlx, s->mlx->win, s->img->img, 0, 0);

			}
		}
      }
	}
}