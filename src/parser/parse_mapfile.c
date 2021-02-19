/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:35:26 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/19 20:38:41 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	parse_res(t_set *set, char *parstr)
{
	int i;
	set->size_x = 0;
	set->size_y = 0;
	char *par;

	i = 0;
	par = parstr;
	while (ft_isspace(*par))
		par++;
	while(!ft_isspace(*par) && ft_isdigit(*par) && i++ < 4)
		set->size_x = set->size_x * 10 + *par++ - '0';
	while (!ft_isspace(*par))
		par++;
	while (ft_isspace(*par))
		par++;
	if (!ft_isdigit(*par) || !par)
		error(set, ER_MAP);
	i = 0;
	if (!*par)
		error(set, ER_MAP);
	while(*par && !ft_isspace(*par) && i++ < 4)
		set->size_y = set->size_y * 10 + *par++ - '0';
}

static	int		check_mapsign(char c)
{
	if (c == '0' || c == '1' || c == '2')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static	int validate_map_line(char *str, t_set *set)
{
	int i;
	char *s;

	s = str;
	i = 0;
	if (ft_strchr(s, '0') || ft_strchr(s, '1'))
	{
		while(*s == ' ')
			s++;
		while (*s)
		{
			if (check_mapsign(*s) || *s == ' ')
				s++;
			else
				error(set, ER_MAP);
		}
		return (1);
	}
	return (0);
}



int		parse_mapfile(t_set *set, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		parse_res(set, &line[1]);
	else if (line[0] == 'N' && line[1] == 'O')
		set->tex->no->path = ft_strtrim(&line[2], " \n\t\v\f\r");
	else if (line[0] == 'S' && line[1] == 'O')
		set->tex->so->path = ft_strtrim(&line[2], " \n\t\v\f\r");
	else if (line[0] == 'W' && line[1] == 'E')
		set->tex->we->path = ft_strtrim(&line[2], " \n\t\v\f\r");
	else if (line[0] == 'E' && line[1] == 'A')
		set->tex->ea->path = ft_strtrim(&line[2], " \n\t\v\f\r");
	else if (line[0] == 'S' && line[1] == ' ')
		set->s = ft_strtrim(&line[1], " \n\t\v\f\r");
	else if (line[0] == 'F' && line[1] == ' ')
		set->f = ft_strtrim(&line[1], " \n\t\v\f\r");
	else if (line[0] == 'C' && line[1] == ' ')
		set->c = ft_strtrim(&line[1], " \n\t\v\f\r");
	else if (validate_map_line(line, set))
		ft_lstadd_back(&set->mlist, ft_lstnew(line));
	else
		return (0);
	return (1);
}