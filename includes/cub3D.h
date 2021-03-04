/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:40:41 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/04 14:54:40 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../src/libft/libft.h"
# include "../minilibx_mms/mlx.h"
# include <utils.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# define SCALE 15
# define SPEED 1

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_dpoint
{
	double x;
	double y;
}				t_dpoint;

typedef struct	s_curspr
{
	double	x;
	double	y;
	double	dist;
}				t_curspr;

typedef struct	s_mlx
{
	void *mlx;
	void *win;
}				t_mlx;

typedef struct	s_img
{
	char		*path;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			wi;
	int			he;
}				t_img;

typedef struct	s_tex
{
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;
	t_img	*spr;
	char	*path;
	int		wi;
	int		he;
	double	wallx;
	double	step;
	double	pos;
	int		x;
	int		y;
}				t_tex;

typedef struct	s_ray
{
	double	dirx;
	double	diry;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	cam_x;
	double	cam_y;
	double	wall;
	double	*buffer;
	int		stepx;
	int		stepy;
	int		side;
}				t_ray;

typedef struct	s_sprite
{
	int		count;
	double	x;
	double	y;
	int		height;
	int		width;
	int		screen_x;
	double	coef;
	double	transform_x;
	double	transform_y;
}				t_sprite;

typedef struct	s_player
{
	double	x;
	double	y;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	char	pos;
	int		up;
	int		down;
	int		left;
	int		right;
	int		lrot;
	int		rrot;
}				t_player;

typedef enum	e_codes
{
	SUCCESS,
	ER_MAP,
	ER_SETTINGS,
	ER_TEXTURE,
	ER_SCREEN,
	ER_OPEN,
	ER_TEXTURESIZE,
	MALLOC
}				t_codes;

typedef struct	s_settings
{
	int			size_x;
	int			size_y;
	t_tex		*tex;
	int			save;
	int			f;
	int			c;
	int			a;
	char		**map;
	t_player	pl;
	t_mlx		*mlx;
	t_list		*mlist;
	t_img		*img;
	t_ray		*ray;
	t_curspr	*spr;
	t_sprite	*sp;
}				t_set;

void			error(t_set *s, int code);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
int				main(int argc, char **argv);
int				main_parser(char *argv, t_set *set);
int				parse_mapfile(t_set *set, char *line);
void			save_colorpar(t_set *set, int *setting, char *str);
int				parse_player(t_set *s);
int				map_validator(t_set *set);
int				check_settings(t_set *set);
int				checker_map(t_set *s);
int				check_texsize(t_set *s);
int				mapfiller(char **map, int y, int x);
int				checkborders(char **map);
void			save_sprites(t_set *s);
int				cube_start(t_set *s);
void			create_mlx(t_set *s);
void			image_refresh(t_set *s);
int				raycaster(t_set *s);
void			sprite_calculator(t_set *s);
void			draw_all(t_set *s, int x);
void			draw_sprites(t_set *s);
void			moveplayer(t_set *s);
void			free_img(t_set *s);
void			save_screenshot(t_set *s);

#endif
