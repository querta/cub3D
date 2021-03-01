/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:35:26 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/01 16:53:05 by mmonte           ###   ########.fr       */
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
		error(set, ER_SETTINGS);
	i = 0;
	if (!*par)
		error(set, ER_SETTINGS);
	while(*par && !ft_isspace(*par) && i++ < 4)
		set->size_y = set->size_y * 10 + *par++ - '0';
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

static int cfcolors(t_set *set, char *str)
{
	char **colors;
	int i;
	int rgb[3];
	int color;

	colors = ft_split(str, ',');
	i = 0;
	while (colors[i])
		i++;
	if (i != 3)
		error(set, ER_SETTINGS);
	while (i--)
	{
		if ((rgb[i] = ft_atoi(colors[i])) > 255)
			error(set, ER_SETTINGS);
	}
	color = (rgb[0]<<16) | (rgb[1]<<8) | (rgb[2]<<0);
	i = 0;
	while (colors[i])
		free(colors[i++]);
	free(colors);
	return (color);
}

static int parsecf(t_set *set, char *line)
{
	int i;
	int k;
	char *str;
	int color;

	i = -1;
	k = 0;
	if (!(str = ft_strtrim(line, " \n\t\v\f\r")))
		error(set, MALLOC);
	while (str[++i])
	{
		if (str[i] == ',' || ft_isdigit(str[i]))
		{
			if (str[i] == ',')
				k++;
		}
		else
			error(set, ER_SETTINGS);
	}
	if (k != 2)
		error(set, ER_SETTINGS);
	color = cfcolors(set, str);
	free(str);
	return (color);
}

int		parse_mapfile(t_set *set, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		parse_res(set, &line[1]);
	else if (line[0] == 'N' && line[1] == 'O')
	{
		if (set->tex->no->path)
			error(set, ER_SETTINGS);
		else
			set->tex->no->path = ft_strtrim(&line[2], " \n\t\v\f\r");
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (set->tex->so->path)
			error(set, ER_SETTINGS);
		else
		set->tex->so->path = ft_strtrim(&line[2], " \n\t\v\f\r");
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		if (set->tex->we->path)
			error(set, ER_SETTINGS);
		else
			set->tex->we->path = ft_strtrim(&line[2], " \n\t\v\f\r");
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		if (set->tex->ea->path)
			error(set, ER_SETTINGS);
		else
			set->tex->ea->path = ft_strtrim(&line[2], " \n\t\v\f\r");
	}
	else if (line[0] == 'S' && ft_strchr(&line[1], '.'))
	{
		if (set->tex->spr->path)
			error(set, ER_SETTINGS);
		else
			set->tex->spr->path = ft_strtrim(&line[1], " \n\t\v\f\r");
	}
	else if (line[0] == 'F')
	{
		if (set->f != -1)
			error(set, ER_SETTINGS);
		else
			set->f = parsecf(set, &line[1]);
	}
	else if (line[0] == 'C')
	{
		if (set->c != -1)
			error(set, ER_SETTINGS);
		else
			set->c = parsecf(set, &line[1]);
	}
	else if (validate_map_line(line, set))
	{
		if (!check_settings(set))
			error(set, ER_SETTINGS);
		ft_lstadd_back(&set->mlist, ft_lstnew(line));
		return (0);
	}
	return (1);
}