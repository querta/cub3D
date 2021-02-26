/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:08:13 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/26 17:22:37 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void		count_sprites(t_set *s, char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '2')
			s->sprites++;
		i++;
	}
}

static	char	**make_map(t_set *s, int size)
{
	t_list	*tmp;
	char	**map;
	int		i;

	tmp = s->mlist;
	if (!(map = ft_calloc(size + 1, sizeof(char *))))
		error(s, MALLOC);
	i = -1;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
		count_sprites(s, map[i]);
	}
	return (map);
}

int			main_parser(char *argv, t_set *set)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error(set, ER_OPEN);
	while (get_next_line(fd, &line))
		parse_mapfile(set, line);
	if (!parse_mapfile(set, line))
		error(set, ER_SETTINGS);
	set->map = make_map(set, ft_lstsize(set->mlist));
	checker(set);
	close(fd);
	return (1);
}
