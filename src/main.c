/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:00:56 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/29 15:29:42 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void create_structs(int argc, char *argv)
{
	t_list	*mlist;
	t_set	set;
	t_mlx	mlx;
	// char	**map;

	
	ft_bzero(&set, sizeof(set));
	ft_bzero(&mlx, sizeof(mlx));
	ft_bzero(&mlist, sizeof(mlist));
	set.mlx = &mlx;
	set.mlist = mlist;
	set.map = main_parser(argc, argv, &set);
	// set.map = main_parser(argc, argv, &set, &set.mlist);
	cube_start(&set);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		create_structs(argc, argv[1]);
	}
	
	// 	int i = -1;
	// while (map[++i])
	// 	ft_putendl_fd(map[i], 1);
	// printf("x:%d\ny:%d\nno:%s\nso:%s\nwe:%s\nea:%s\ns:%s\nf:%s\nc:%s\n", set.size_x, set.size_y, set.no, set.so, set.we, set.ea, set.s, set.f, set.c );

	return (0);
}