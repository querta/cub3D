/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:35:26 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/02 16:30:12 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	parse_res(t_set *set, char *parstr)
{
	int		i;
	char	*par;

	set->size_x = 0;
	set->size_y = 0;
	i = 0;
	par = parstr;
	while (ft_isspace(*par))
		par++;
	while (!ft_isspace(*par) && ft_isdigit(*par) && i++ < 4)
		set->size_x = set->size_x * 10 + *par++ - '0';
	while (ft_isdigit(*par))
		par++;
	while (ft_isspace(*par))
		par++;
	if (!ft_isdigit(*par) || !par)
		error(set, ER_SETTINGS);
	i = 0;
	while (*par && !ft_isspace(*par) && i++ < 4)
	{
		if (!ft_isdigit(*par))
			error(set, ER_SETTINGS);
		set->size_y = set->size_y * 10 + *par++ - '0';
	}
}

static	int	validate_map_line(char *str, t_set *set)
{
	int		i;
	char	*s;

	s = str;
	i = 0;
	if (ft_strchr(s, '0') || ft_strchr(s, '1'))
	{
		while (*s == ' ')
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

static void	save_parametr(t_set *set, char **setting, char *str)
{
	if (*setting)
		error(set, ER_SETTINGS);
	else
		*setting = ft_strtrim(str, " \n\t\v\f\r");
}

int			parse_mapfile(t_set *set, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		parse_res(set, &line[1]);
	else if (line[0] == 'N' && line[1] == 'O')
		save_parametr(set, &set->tex->no->path, &line[2]);
	else if (line[0] == 'S' && line[1] == 'O')
		save_parametr(set, &set->tex->so->path, &line[2]);
	else if (line[0] == 'W' && line[1] == 'E')
		save_parametr(set, &set->tex->we->path, &line[2]);
	else if (line[0] == 'E' && line[1] == 'A')
		save_parametr(set, &set->tex->ea->path, &line[2]);
	else if (line[0] == 'S' && ft_strchr(&line[1], '.'))
		save_parametr(set, &set->tex->spr->path, &line[1]);
	else if (line[0] == 'F')
		save_colorpar(set, &set->f, &line[1]);
	else if (line[0] == 'C')
		save_colorpar(set, &set->c, &line[1]);
	else if (validate_map_line(line, set))
	{
		if (!check_settings(set))
			error(set, ER_SETTINGS);
		ft_lstadd_back(&set->mlist, ft_lstnew(line));
		return (0);
	}
	// else if (line[0] == '\0' || ft_isspace(line[0]))
	// 	return(0);
	else if (!empty_line(set, &line[1]))
		error(set, ER_SETTINGS);
	return (1);
}
