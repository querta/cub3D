/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:38:20 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/15 18:39:48 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	int player_fill(t_set *s, char *map, int y, char c)
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

int		parse_player(t_set *s)
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