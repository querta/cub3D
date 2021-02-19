/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:32:10 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/19 12:25:59 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	int	check_settings(t_set *set)
{
	if (set->no.path && set->so.path && set->we.path && set->ea.path)
		return (1);
	else if (set->s && set->f && set->c)
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