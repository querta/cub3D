/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:00:56 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/19 22:22:56 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void textures_init(t_set *set)
// {
// 	t_tex no;
// 	t_tex so;
// 	t_tex we;
// 	t_tex ea;
// 	t_tex tex;

// 	ft_bzero(&no, sizeof(no));
// 	ft_bzero(&so, sizeof(so));
// 	ft_bzero(&we, sizeof(we));
// 	ft_bzero(&ea, sizeof(ea));
// 	ft_bzero(&tex, sizeof(tex));
// 	set->no = no;
// 	set->so = so;
// 	set->we = we;
// 	set->ea = ea;
// 	set->tex = tex;
// }

int create_structs(int argc, char *argv)
{
	t_set	*set;
	t_list	*mlist;
	t_mlx	mlx;
	t_player player;
	
	// ft_bzero(&set, sizeof(set));
	set = (t_set *)malloc(sizeof(t_set));
	ft_bzero(&mlx, sizeof(mlx));
	ft_bzero(&mlist, sizeof(mlist));
	ft_bzero(&player, sizeof(player));
	set->tex = (t_tex *)malloc(sizeof(t_tex));
	set->tex->no = (t_img *)malloc(sizeof(t_img));
	set->tex->so = (t_img *)malloc(sizeof(t_img));
	set->tex->we = (t_img *)malloc(sizeof(t_img));
	set->tex->ea = (t_img *)malloc(sizeof(t_img));
	set->mlx = &mlx;
	set->mlist = mlist;
	set->save = argc - 2;

	main_parser(argv, set);
	cube_start(set);

	
	return (1);
}


static int check_saveparam(char *str)
{
	size_t len;

	len = ft_strlen(str);
	if (str && len == 6)
	{
		if (!ft_strncmp(str, "--save", 6))
			return(1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_putendl_fd("No map.cub", 1);
	if (argc == 2)
		create_structs(argc, argv[1]);
	if (argc == 3)
	{
		if (check_saveparam(argv[2]))
			create_structs(argc, argv[1]);
		else
			ft_putendl_fd("Invalid argument", 1);
	}
	else
		ft_putendl_fd("Too many arguments", 1);

	return (0);
}