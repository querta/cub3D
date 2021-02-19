/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:01:22 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/19 21:52:07 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


static	int             keypress(int keycode, t_set *s)
{
	double coords;

	coords = (double)SPEED / 100;
	if (keycode == 53)
		error(s, 0);
	if (keycode == 13 || keycode == 126)
		s->pl.up = 1;
	if (keycode == 1 || keycode == 125)
		s->pl.down = 1;
	// if (keycode == 0)
	// 	s->pl.left = 1;
	// if (keycode == 2)
	// 	s->pl.right = 1;
	if (keycode == 123)
		s->pl.lrot = 1;
	if (keycode == 124)
		s->pl.rrot = 1;
	if (keycode == 0)
		s->pl.lrot = 1;
	if (keycode == 2)
		s->pl.rrot = 1;

	return (0);
}

static	int             keyrelease(int keycode, t_set *s)
{
	double coords;

	coords = (double)SPEED / 100;;
	if (keycode == 13 || keycode == 126)
		s->pl.up = 0;
	if (keycode == 1 || keycode == 125)
		s->pl.down = 0;
	// if (keycode == 0)		
	// 	s->pl.left = 0;
	// if (keycode == 2)
	// 	s->pl.right = 0;
	if (keycode == 123)
		s->pl.lrot = 0;
	if (keycode == 124)
		s->pl.rrot = 0;
	if (keycode == 0)
		s->pl.lrot = 0;
	if (keycode == 2)
		s->pl.rrot = 0;
	return (0);
}

static	int closewin(t_set *s)
{
	error(s, SUCCESS);
	return (1);
}

void save_screen(t_set *s)
{
	printf("savescreen∂\n");
	// printf("img - %p\n", s->img->img);
	raycaster(s);
	printf("%p\n", s->img->img);
}

int			cube_start(t_set *s)
{
	// int i = -1;
	// write(1, "map\n", 4);
	// while (s->map[++i])
	// 	ft_putendl_fd(s->map[i], 1);
	create_mlx(s);
	if (!s->save)
	{
		mlx_hook(s->mlx->win, 2, 1L<<0, keypress, s);
		mlx_hook(s->mlx->win, 17, 0L, closewin, s);

		mlx_loop_hook(s->mlx->mlx, raycaster, s);
		mlx_key_hook(s->mlx->win, keyrelease, s);

		mlx_loop(s->mlx->mlx);
	}
	else
		save_screen(s);
	return (0);
}
