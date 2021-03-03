/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:32:10 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/03 18:32:02 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_texsize(t_set *s)
{
	if (s->tex->no->he == s->tex->so->he &&
		s->tex->no->he == s->tex->we->he && s->tex->no->he == s->tex->ea->he)
	{
		if (s->tex->no->wi == s->tex->so->wi
			&& s->tex->no->wi == s->tex->we->wi
			&& s->tex->no->wi == s->tex->ea->wi)
			return (1);
	}
	return (0);
}

int	check_settings(t_set *set)
{
	if (set->tex && set->tex->no && set->tex->so
		&& set->tex->we && set->tex->ea)
	{
		if (set->img && set->tex->no->path && set->tex->so->path)
		{
			if (set->tex->we->path && set->tex->ea->path && set->tex->spr->path)
			{
				if (set->tex->spr->path && set->c >= 0 && set->f >= 0)
					return (1);
			}
		}
	}
	return (0);
}

int	map_validator(t_set *set)
{
	if (!parse_player(set))
		error(set, ER_MAP);
	if (!checker_map(set))
		error(set, ER_MAP);
	return (1);
}
