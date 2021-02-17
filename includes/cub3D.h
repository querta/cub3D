/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:57:56 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/17 18:24:00 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../src/libft/libft.h"
# include "./utils.h"
// # include "./mlx.h"
// # include "../src/minilibx_mms/mlx.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# define SCALE 15
# define SPEED 0.05

# include <stdio.h>

typedef struct s_mlx
{
	void *mlx;
	void *win;
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
	double dir;
	int up;
	int down;
	int left;
	int right;

}				t_player;

typedef enum		e_codes
{
	SUCCESS,
	ER_MAP,
	ER_SETTINGS,
	MALLOC
}					t_codes;

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
	t_ray *ray;
}				t_set;

void error(t_set *s, int code);
void            my_mlx_pixel_put(t_img *data, int x, int y, int color);
int				main(int argc, char **argv);
int				main_parser(int argc, char *argv, t_set *set);
int		parse_mapfile(t_set *set, char *line);
int		parse_player(t_set *s);
int				checker(t_set *set);
int		checker_map(t_set *s);
int				checker_filler_map(t_set *s, char **map);

// char	**make_map(t_set *s, int size);
int				cube_start(t_set *set);
void			create_mlx(t_set *s);
// int	draw_map(t_set *s);
int		draw_main(t_set *s);
void	moveplayer(t_set *s);
void	free_img(t_set *s);



#endif