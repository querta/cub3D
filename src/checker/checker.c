/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:32:10 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/02 15:47:21 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
