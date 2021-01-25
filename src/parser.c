/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:08:13 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/25 19:08:32 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	char	**make_map(t_list **head, int size)
{
	t_list *tmp;
	char **map;
	
	tmp = *head;
	map = ft_calloc(size + 1, sizeof(char *));
	int i = -1;
	
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	return (map);
}

static	int parse_map(t_list **head, t_set *set, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		set->r = &(line[2]);
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
	else if (line[0] == '\0')
		return (0);
	else
		ft_lstadd_back(head, ft_lstnew(line));
	
	return (1);
}

char		**main_parser(int argc, char *argv, t_set *set, t_list **head)
{
	int		fd;
	char	*line;
	char	**map;

	line = NULL;
	*head = NULL;	
	fd = 0;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv, O_RDONLY);
	else
		return (NULL);
	while (get_next_line(fd, &line))
		parse_map(head, set, line);
	parse_map(head, set, line);
	map = make_map(head, ft_lstsize(*head));	
	if (argc == 2)
		close(fd);
	return (map);
}