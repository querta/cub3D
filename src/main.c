/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:00:56 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/27 20:51:34 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int create_structs(int argc, char *argv)
{
	t_set	*set;
	t_list	*mlist;
	t_mlx	mlx;
	t_player player;
	
	if (!(set = (t_set *)malloc(sizeof(t_set))))
	{
		ft_putendl_fd("Memory allocation error", 1);
		exit(1);	
	}
	ft_bzero(&mlx, sizeof(mlx));
	ft_bzero(&mlist, sizeof(mlist));
	ft_bzero(&player, sizeof(player));
	set->tex = (t_tex *)malloc(sizeof(t_tex));
	set->tex->no = (t_img *)malloc(sizeof(t_img));
	set->tex->so = (t_img *)malloc(sizeof(t_img));
	set->tex->we = (t_img *)malloc(sizeof(t_img));
	set->tex->ea = (t_img *)malloc(sizeof(t_img));
	set->tex->spr = (t_img *)malloc(sizeof(t_img));
	set->ray = (t_ray *)malloc(sizeof(t_ray));
	set->sp = (t_sprite *)malloc(sizeof(t_sprite));
	set->img = (t_img *)malloc(sizeof(t_img));
	set->sp->count = 0;
	set->mlx = &mlx;
	set->mlist = mlist;
	set->save = argc - 2;
	main_parser(argv, set);
	set->spr = (t_curspr *)malloc(sizeof(t_curspr) * set->sp->count);
	save_sprites(set);
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