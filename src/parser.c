/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:08:13 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/26 19:36:27 by mmonte           ###   ########.fr       */
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
}

static	char	**make_map(t_list **mlist, int size)
{
	t_list	*tmp;
	char	**map;
	int		i;

	tmp = *mlist;
	map = ft_calloc(size + 1, sizeof(char *));
	i = -1;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	return (map);
}

int				check_map (char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == '2')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static	int		parse_map(t_list **mlist, t_set *set, char *line)
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
	else if (check_map(line[0]))
		ft_lstadd_back(mlist, ft_lstnew(line));
	else
		return (0);
	// else if (line[0] == '\0')
	// 	return (0);
	return (1);
}

char			**main_parser(int argc, char *argv, t_set *set, t_list **mlist)
{
	int		fd;
	char	*line;
	char	**map;

	line = NULL;
	*mlist = NULL;
	fd = 0;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv, O_RDONLY);
	else
		return (NULL);
	while (get_next_line(fd, &line))
		parse_map(mlist, set, line);
	parse_map(mlist, set, line);
	map = make_map(mlist, ft_lstsize(*mlist));
	if (argc == 2)
		close(fd);
	return (map);
}
