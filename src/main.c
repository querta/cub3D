/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:00:56 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/28 15:51:38 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		main(int argc, char **argv)
{
	t_list	*mlist;
	t_set	set;
	// char	**map;

	ft_bzero(&set, sizeof(set));
	set.map = main_parser(argc, argv[1], &set, &mlist);
	cube_start(&set);
	// 	int i = -1;
	// while (map[++i])
	// 	ft_putendl_fd(map[i], 1);
	// printf("x:%d\ny:%d\nno:%s\nso:%s\nwe:%s\nea:%s\ns:%s\nf:%s\nc:%s\n", set.size_x, set.size_y, set.no, set.so, set.we, set.ea, set.s, set.f, set.c );

	return (0);
}