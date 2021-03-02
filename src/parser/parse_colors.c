/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:27:31 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/02 14:51:13 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

static	int parsecf(t_set *set, char *line)
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
		if (str[i] == ',')
			k++;
	}
	if (k != 2)
		error(set, ER_SETTINGS);
	color = cfcolors(set, str);
	free(str);
	return (color);
}

void save_colorpar(t_set *set, int *setting, char *str)
{
	if (*setting != -1)
		error(set, ER_SETTINGS);
	else
		*setting = parsecf(set, str);
}