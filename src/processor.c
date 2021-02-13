/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:01:22 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/13 20:15:40 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


static	int             keypress(int keycode, t_set *s)
{
	double coords;

	coords = (double)SPEED / 100;
	mlx_clear_window(s->mlx->mlx, s->mlx->win);
	if (keycode == 53)
		error(s, 0);
	if (keycode == 13 || keycode == 126)	// up
		s->pl.up = 1;
	if (keycode == 1 || keycode == 125)		// down
		s->pl.down = 1;
	if (keycode == 0 || keycode == 123)		// left
		s->pl.left = 1;
	if (keycode == 2 || keycode == 124)		//right
		s->pl.right = 1;
	draw_map(s);

	return (0);
}

static	int             keyrelease(int keycode, t_set *s)
{
	double coords;

	coords = (double)SPEED / 100;
	mlx_clear_window(s->mlx->mlx, s->mlx->win);
	if (keycode == 13 || keycode == 126)	// up
		s->pl.up = 0;
	if (keycode == 1 || keycode == 125)		// down
		s->pl.down = 0;
	if (keycode == 0 || keycode == 123)		// left
		s->pl.left = 0;
	if (keycode == 2 || keycode == 124)		//right
		s->pl.right = 0;
	draw_map(s);

	return (0);
}

static	int closewin(t_set *s)
{
	error(s, SUCCESS);
	return (1);
}

int			cube_start(t_set *s)
{

	int i = -1;
	write(1, "map\n", 4);
	while (s->map[++i])
		ft_putendl_fd(s->map[i], 1);
	create_mlx(s);
	printf("x:%d\ny:%d\n", s->size_x, s->size_y);

	mlx_hook(s->mlx->win, 2, 1L<<0, keypress, s);
	mlx_hook(s->mlx->win, 17, 0L, closewin, s);

	mlx_key_hook(s->mlx->win, keyrelease, s);
	mlx_loop_hook(s->mlx->mlx, draw_map, s);
	// printf("%p\n", s->mlx->img);
	printf("%p\n", s->img);
	
	mlx_loop(s->mlx->mlx);
	return (0);
}
