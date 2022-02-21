/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:38:20 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/03 17:44:55 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_coordsew(t_set *s, int dirx, double ply)
{
	s->pl.dirx = dirx;
	s->pl.diry = 0;
	s->pl.planex = 0;
	s->pl.planey = ply;
}

static void	player_coordsns(t_set *s, int diry, double plx)
{
	s->pl.dirx = 0;
	s->pl.diry = diry;
	s->pl.planex = plx;
	s->pl.planey = 0;
}

static int	player_fill(t_set *s, char *map, int y, char c)
{
	char *pos;

	pos = 0;
	if ((pos = ft_strchr(map, c)))
	{
		if (!s->pl.pos)
		{
			s->pl.pos = c;
			s->pl.x = (double)(pos - &map[0]) + 0.1;
			s->pl.y = (double)y + 0.1;
			if (c == 'N')
				player_coordsns(s, -1, 0.66);
			if (c == 'S')
				player_coordsns(s, 1, -0.66);
			if (c == 'E')
				player_coordsew(s, 1, 0.66);
			if (c == 'W')
				player_coordsew(s, -1, -0.66);
		}
		else
			return (0);
	}
	return (1);
}

int			parse_player(t_set *s)
{
	int		i;
	int		y;
	char	*c;

	c = "NSEW";
	i = 0;
	y = 0;
	while (s->map[y])
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
