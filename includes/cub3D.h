/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:57:56 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/28 17:56:35 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../src/libft/libft.h"
# include "./utils.h"
# include <mlx.h>
# include <fcntl.h>
# define SCALE 15

# include <stdio.h>

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
}				t_set;

int				main(int argc, char **argv);
char			**main_parser(int argc, char *argv, t_set *set, t_list **head);
int			cube_start(t_set *set);

#endif