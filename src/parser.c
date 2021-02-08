/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:08:13 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/08 14:31:48 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	parse_res(t_set *set, char *par)
{
	int i;
	set->size_x = 0;
	set->size_y = 0;

	i = 0;
	par = strstart(par);
	while(!ft_isspace(*par) && i++ < 4 && ft_isdigit(*par))
		set->size_x = set->size_x * 10 + *par++ - '0';
	if (!ft_isdigit(*par) && !ft_isspace(*par) && *par)
		error(set, ER_MAP);
	while(*par && !ft_isspace(*par))
		par++;
	while(*par && ft_isspace(*par))
		par++;
	i = 0;
	if (!*par)
		error(set, ER_MAP);
	while(*par && !ft_isspace(*par) && i++ < 4)
		set->size_y = set->size_y * 10 + *par++ - '0';
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
				s->pl.dir = M_PI_2; //1.5708; // 90 
			if (c == 'S')
				s->pl.dir = 3 * M_PI_2; // 4.7124; // 270
			if (c == 'E')
				s->pl.dir = M_PI; // 3.1416; // 180
			if (c == 'W')
				s->pl.dir = 0;
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
	if (!player_parser(set))
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

int	check_settings(t_set *set)
{
	if (set->no && set->so && set->we && set->ea && set->s && set->f && set->c)
		return (1);
	else
		return (0);
}

int		check_mapsign(char c)
{
	if (c == '0' || c == '1' || c == '2')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int check_map(char *str, t_set *set)
{
	int i;
	char *s;

	s = str;
	i = 0;
	if (ft_strchr(s, '0') || ft_strchr(s, '1'))
	{
		while(ft_isspace(*s))
			s++;
		while (*s)
		{
			if (check_mapsign(*s) || ft_isspace(*s))
				s++;
			else
				error(set, ER_MAP);
		}
		return (1);
	}
	return (0);
}

static	int		parse_map(t_set *set, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		parse_res(set, &line[1]);
	else if (line[0] == 'N' && line[1] == 'O')
		set->no = strstart(&line[2]);
	else if (line[0] == 'S' && line[1] == 'O')
		set->so = strstart(&line[2]);
	else if (line[0] == 'W' && line[1] == 'E')
		set->we = strstart(&line[2]);
	else if (line[0] == 'E' && line[1] == 'A')
		set->ea = strstart(&line[2]);
	else if (line[0] == 'S' && line[1] == ' ')
		set->s = strstart(&line[1]);
	else if (line[0] == 'F' && line[1] == ' ')
		set->f = strstart(&line[1]);
	else if (line[0] == 'C' && line[1] == ' ')
		set->c = strstart(&line[1]);
	else if (check_map(line, set))
		ft_lstadd_back(&set->mlist, ft_lstnew(line));
	else
		return (0);
	return (1);
}

int checker(t_set *set)
{
	if (!map_checker(set))
		error(set, ER_MAP);
	if (!check_settings(set))
		error(set, ER_SETTINGS);
	return (1);
}

int			main_parser(int argc, char *argv, t_set *set)
{
	int		fd;
	char	*line;

	line = NULL;
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
	checker(set);
	if (argc == 2)
		close(fd);
	return (1);
}
