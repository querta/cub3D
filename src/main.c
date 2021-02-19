/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:00:56 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/19 12:34:34 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void textures_init(t_set *set)
{
	t_tex no;
	t_tex so;
	t_tex we;
	t_tex ea;

	ft_bzero(&no, sizeof(no));
	ft_bzero(&so, sizeof(so));
	ft_bzero(&we, sizeof(we));
	ft_bzero(&ea, sizeof(ea));
	set->no = no;
	set->so = so;
	set->we = we;
	set->ea = ea;
}

int create_structs(int argc, char *argv)
{
	t_list	*mlist;
	t_set	set;
	t_mlx	mlx;
	t_player player;
	
	ft_bzero(&set, sizeof(set));
	ft_bzero(&mlx, sizeof(mlx));
	ft_bzero(&mlist, sizeof(mlist));
	ft_bzero(&player, sizeof(player));
	set.mlx = &mlx;
	set.mlist = mlist;
	textures_init(&set);

	main_parser(argc, argv, &set);
	cube_start(&set);

	
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		create_structs(argc, argv[1]);
	}
	
	// 	int i = -1;
	// while (set.map[++i])
	// 	ft_putendl_fd(map[i], 1);

	return (0);
}