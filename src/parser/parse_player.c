/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:38:20 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/25 18:12:07 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	player_coordsew(t_set *s, int dirx, double ply)
{
	s->pl.dirX = dirx;
	s->pl.dirY = 0;
	s->pl.planeX = 0;
	s->pl.planeY = ply;
}

static void	player_coordsns(t_set *s, int diry, double plx)
{
	s->pl.dirX = 0; 
	s->pl.dirY = diry;
	s->pl.planeX = plx;
	s->pl.planeY = 0; 
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
	int 	y;
	char	*c;
	int		ret;

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
