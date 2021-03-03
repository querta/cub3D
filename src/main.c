/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:00:56 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/03 17:58:25 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		struct_init(t_set *set)
{
	set->tex = (t_tex *)ft_calloc(1, sizeof(t_tex));
	set->tex->no = (t_img *)ft_calloc(1, sizeof(t_img));
	set->tex->so = (t_img *)ft_calloc(1, sizeof(t_img));
	set->tex->we = (t_img *)ft_calloc(1, sizeof(t_img));
	set->tex->ea = (t_img *)ft_calloc(1, sizeof(t_img));
	set->tex->spr = (t_img *)ft_calloc(1, sizeof(t_img));
	set->ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
	set->sp = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	set->img = (t_img *)ft_calloc(1, sizeof(t_img));
	set->f = -1;
	set->c = -1;
}

int			create_structs(int argc, char *argv)
{
	t_set		*set;
	t_list		*mlist;
	t_player	player;

	if (!(set = (t_set *)ft_calloc(1, sizeof(t_set))))
	{
		ft_putendl_fd("Memory allocation error", 1);
		exit(1);
	}
	ft_bzero(&mlist, sizeof(mlist));
	ft_bzero(&player, sizeof(player));
	struct_init(set);
	set->mlist = mlist;
	set->mlx = (t_mlx *)ft_calloc(1, sizeof(t_mlx));
	set->save = argc - 2;
	main_parser(argv, set);
	set->spr = (t_curspr *)ft_calloc(set->sp->count,
		sizeof(t_curspr) * set->sp->count);
	save_sprites(set);
	cube_start(set);
	return (1);
}

static int	check_filename(char *str)
{
	size_t len;

	len = ft_strlen(str) - 1;
	if (str[len] == 'b' && str[len - 1] == 'u'
		&& str[len - 2] == 'c' && str[len - 3] == '.')
		return (1);
	return (0);
}

static int	check_saveparam(char *str)
{
	size_t len;

	len = ft_strlen(str);
	if (str && len == 6)
	{
		if (!ft_strncmp(str, "--save", 6))
			return (1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc == 1)
		ft_putendl_fd("No map.cub", 1);
	if (argc == 2)
	{
		if (check_filename(argv[1]))
			create_structs(argc, argv[1]);
		else
			ft_putendl_fd("Invalid mapfilename", 1);
	}
	else if (argc == 3)
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
