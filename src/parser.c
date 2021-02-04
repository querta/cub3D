/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:08:13 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/04 17:08:51 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	parse_res(t_set *set, char *par)
{
	set->size_x = 0;
	set->size_y = 0;

	while(*par != ' ')
		set->size_x = set->size_x * 10 + *par++ - '0';
	par++;
	while(*par)
		set->size_y = set->size_y * 10 + *par++ - '0';

	// mlx_get_screen_size(mlx, &max_width, &max_height)
}

int player_fill(t_set *s, char *map, int y, char c)
{
	char *pos;

	pos = 0;
	if ((pos = ft_strchr(map, c)))
	{
		if (!s->pl.pos)
		{
			s->pl.pos = c;
			s->pl.x = (double)(pos - &map[0]);
			s->pl.y = (double)y;
			if (c == 'N')
				s->pl.dir = 0;
			if (c == 'S')
				s->pl.dir = 3.1416; // 180
			if (c == 'E')
				s->pl.dir = 1.5708; // 90
			if (c == 'W')
				s->pl.dir = 4.7124; // 270
		}
		else
			return (0);
	}
	return (1);
}

int		player_parser(t_set *s)
{
	int i;
	int y;
	char *c;
	int ret;

	ret = 0;
	c = "NSEW";
	i = 0;
	y = 0;
	while(s->map[y])
	{
		i = 0;
		while (c[i])
		{
			if (!player_fill(s, s->map[y], y, c[i]))
				return (0);
			i++;
		}
		y++;
	}
	if (!s->pl.pos)
		return (0);
	return (1);
}

int		map_checker(t_set *set)
{
	if (player_parser(set) == 0)
		return (0);
	return (1);
}


static	char	**make_map(t_set *s, int size)
{
	t_list	*tmp;
	char	**map;
	int		i;

	tmp = s->mlist;
	map = ft_calloc(size + 1, sizeof(char *));
	i = -1;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	return (map);
}

int				check_mapsign(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == '2')
		return (1);
	// else if (player_ch(c))
	// 	return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (-1);
}

static	int		parse_map(t_set *set, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		parse_res(set, &line[2]);
	else if (line[0] == 'N' && line[1] == 'O')
		set->no = &(line[3]);
	else if (line[0] == 'S' && line[1] == 'O')
		set->so = &(line[3]);
	else if (line[0] == 'W' && line[1] == 'E')
		set->we = &(line[3]);
	else if (line[0] == 'E' && line[1] == 'A')
		set->ea = &(line[3]);
	else if (line[0] == 'S' && line[1] == ' ')
		set->s = &(line[3]);
	else if (line[0] == 'F' && line[1] == ' ')
		set->f = &(line[3]);
	else if (line[0] == 'C' && line[1] == ' ')
		set->c = &(line[3]);
	else if (check_mapsign(line[0]))
		ft_lstadd_back(&set->mlist, ft_lstnew(line));
	else
		return (-1);
	return (1);
}

int			main_parser(int argc, char *argv, t_set *set)
{
	int		fd;
	char	*line;
	// char	**map;

	line = NULL;
	// *set->mlist = NULL;
	fd = 0;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv, O_RDONLY);
	else
		return (0);
	while (get_next_line(fd, &line))
		parse_map(set, line);
	parse_map(set, line);
	set->map = make_map(set, ft_lstsize(set->mlist));
	if (!map_checker(set))
		return (0);
	if (argc == 2)
		close(fd);
	return (1);
}
