/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:57:56 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/25 19:22:26 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../src/libft/libft.h"
# include "./utils.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# define SCALE 15
# define SPEED 0.05

# include <stdio.h>


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

typedef	struct s_sprite
{
	double x;
	double y;
	double dist;
	t_spr *next;
}				t_spr;

typedef struct s_mlx
{
	void *mlx;
	void *win;
}				t_mlx;

typedef struct  s_img
{
	char		*path;
	void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_img;

typedef struct s_tex
{
	t_img *no;
	t_img *so;
	t_img *we;
	t_img *ea;
	char *path;
	int wi;
	int he;
	double wallx;
	double step;
	double pos;
	int x;
	int y;
}				t_tex;


typedef struct s_ray
{
	double dirX;
	double dirY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double cameraX;
	double cameraY;
	double wall;
	int stepX;
	int stepY;
	int side;
}			t_ray;

typedef struct s_player
{
	double x;
	double y;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	char pos;
	int up;
	int down;
	int left;
	int right;
	int	lrot;
	int rrot;
}				t_player;

typedef enum		e_codes
{
	SUCCESS,
	ER_MAP,
	ER_SETTINGS,
	ER_TEXTURE,
	ER_SCREEN,
	ER_OPEN,
	MALLOC
}					t_codes;

typedef	struct	s_settings
{
	int size_x;
	int size_y;
	t_tex *tex;
	int save;
	char *s;
	int f;
	int	c;
	char **map;
	t_player pl;
	t_mlx *mlx;
	t_list *mlist;
	t_img *img;
	t_ray *ray;
	t_spr *spr;
}				t_set;

void error(t_set *s, int code);
void            my_mlx_pixel_put(t_img *data, int x, int y, int color);
int				main(int argc, char **argv);
int				main_parser(char *argv, t_set *set);
int		parse_mapfile(t_set *set, char *line);
int		parse_player(t_set *s);
int				checker(t_set *set);
int		checker_map(t_set *s);
int				checker_filler_map(t_set *s, char **map);

int			cube_start(t_set *s);
void			create_mlx(t_set *s);
void		image_refresh(t_set *s);
int				raycaster(t_set *s);
void	draw_all(t_set *s, int x);
void	moveplayer(t_set *s);
void	free_img(t_set *s);
void	save_screenshot(t_set *s);



#endif