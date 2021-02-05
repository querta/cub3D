/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:57:56 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/05 19:33:37 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../src/libft/libft.h"
# include "./utils.h"
// # include "./mlx.h"
# include "../src/minilibx_mms/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# define SCALE 15
# define SPEED 0.025

# include <stdio.h>

typedef struct s_mlx
{
	void *mlx;
	void *win;
	void *img;
}				t_mlx;

typedef struct  s_img
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_img;

typedef struct s_point
{
	int x;
	int y;
}			t_point;

typedef struct s_dpoint
{
	double x;
	double y;
}			t_dpoint;

typedef struct s_player
{
	double x;
	double y;
	char pos;
	double dir;
	int up;
	int down;
	int left;
	int right;
	int start;
	int end;
}				t_player;


typedef	struct	s_settings
{
	int size_x;
	int size_y;
	char *no;
	char *so;
	char *we;
	char *ea;
	char *s;
	char *f;
	char *c;
	char **map;
	t_player pl;
	t_mlx *mlx;
	t_list *mlist;
	t_img *img;
	// t_img *img;
}				t_set;

int				main(int argc, char **argv);
int				main_parser(int argc, char *argv, t_set *set);
int				cube_start(t_set *set);

#endif