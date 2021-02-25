/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:32:10 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/25 18:31:55 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	int	check_settings(t_set *set)
{
	if (set->tex && set->tex->no && set->tex->so && set->tex->we && set->tex->ea)
		return (1);
	else if (set->img && set->tex->no->path && set->tex->so->path)
		return (1);
	else if (set->tex->we->path && set->tex->ea->path)
		return (1);
	else if (set->s)
		return (1);
	else
		return (0);
}

int checker(t_set *set)
{
	if (!parse_player(set))
		error(set, ER_MAP);
	if (!checker_map(set))
		error(set, ER_MAP);
	if (!check_settings(set))
		error(set, ER_SETTINGS);
	return (1);
}