/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:01:22 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/08 15:37:26 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



// void	draw_player(t_set *s)
// {
// 	t_dpoint point;
// 	t_dpoint end;
// 	double speed;
	
// 	speed = (double)SPEED / 30;
// 	if (s->mlx->img)
// 		mlx_destroy_image(s->mlx->mlx, s->mlx->img);
// 	ft_bzero(&point, sizeof(t_point));
// 	if (s->pl.up)
// 	{
// 		s->pl.y -= sin(s->pl.dir) * speed;
// 		s->pl.x -= cos(s->pl.dir) * speed;
// 	}
// 	if (s->pl.down)
// 	{
// 		s->pl.y += sin(s->pl.dir) * speed;
// 		s->pl.x += cos(s->pl.dir) * speed;
// 	}
// 	if (s->pl.left)
// 		s->pl.dir -= 0.1;
// 	if (s->pl.right)
// 		s->pl.dir += 0.1;
// 	point.x = s->pl.x;
// 	point.y = s->pl.y;
// 	end.x = (point.x + 1) * SCALE;
// 	end.y = (point.y + 1) * SCALE;
// 	point.x *= SCALE;
// 	point.y *= SCALE;
// 	while (point.y < end.y)
// 	{
// 		while (point.x < end.x)
// 			my_mlx_pixel_put(s->img, point.x++, point.y, 0x0000FF);
// 		point.x -= SCALE;
// 		point.y++;
// 	}
// }






// void	draw_player(t_set *s)	// без углов
// {
// 	t_dpoint point;
// 	t_dpoint end;
// 	double coords;
	
// 	coords = (double)SPEED / 100;
// 	if (s->mlx->img)
// 		mlx_destroy_image(s->mlx->mlx, s->mlx->img);
// 	ft_bzero(&point, sizeof(t_point));
// 	if (s->pl.up)
// 		s->pl.y -= coords;
// 	if (s->pl.down)
// 		s->pl.y += coords;
// 	if (s->pl.left)
// 		s->pl.x -= coords;
// 	if (s->pl.right)
// 		s->pl.x += coords;
// 	point.x = s->pl.x;
// 	point.y = s->pl.y;
// 	end.x = (point.x + 1) * SCALE;
// 	end.y = (point.y + 1) * SCALE;
// 	point.x *= SCALE;
// 	point.y *= SCALE;
// 	while (point.y < end.y)
// 	{
// 		while (point.x < end.x)
// 			my_mlx_pixel_put(s->img, point.x++, point.y, 0x0000FF);
// 		point.x -= SCALE;
// 		point.y++;
// 	}
// 	// point.x = (float)s->pl.x;
// 	// point.y = (float)s->pl.y;
// 	// img_scale(point, s, 0x0000FF);
// }



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

// int             keypress(int keycode, t_set *s)
// {
// 	double coords;

// 	coords = (double)SPEED / 100;
// 	mlx_clear_window(s->mlx->mlx, s->mlx->win);
	
// 	if (keycode == 53)
// 		exit(0);
// 	if (keycode == 13 || keycode == 126)	// up
// 	{
// 		s->pl.y -= sin(s->pl.dir) * 0.25;
// 		s->pl.x -= cos(s->pl.dir) * 0.25;
// 	}
// 	if (keycode == 1 || keycode == 125)		// down
// 	{
// 		s->pl.y += sin(s->pl.dir) * 0.25;
// 		s->pl.x += cos(s->pl.dir) * 0.25;
// 	}
// 	if (keycode == 0 || keycode == 123)		// left
// 		s->pl.dir -= 0.1;
// 	if (keycode == 2 || keycode == 124)		//right
// 		s->pl.dir += 0.1;
// 	printf("dir:%f, x=%f, y=%f\n", s->pl.dir, s->pl.x, s->pl.y);

// 	draw_map(s);
// 	return (0);
// }


int			cube_start(t_set *s)
{

	int i = 0;
	write(1, "map\n", 4);
	while (s->map[++i])
		ft_putendl_fd(s->map[i], 1);
	create_mlx(s);
	printf("x:%d\ny:%d\n", s->size_x, s->size_y);

	mlx_hook(s->mlx->win, 2, 1L<<0, keypress, s);
	mlx_hook(s->mlx->win, 17, 0L, closewin, s);

	mlx_key_hook(s->mlx->win, keyrelease, s);
	mlx_loop_hook(s->mlx->mlx, draw_map, s);
	printf("%p\n", s->mlx->win);
	
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