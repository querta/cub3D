/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:02:28 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/05 17:57:56 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int				check_mapsign(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == '2')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (-1);
}

int ft_isspace(char c)
{
	if (c == '\t' || c == '\n')
		return (1);
	if (c == '\v' || c == '\f')
		return (1);
	if (c == '\r' || c == ' ')
		return (1);
	return (0);
}

char	*strstart(char *str)
{
	char *c;

	c = str;
	if (!ft_isspace(*c))
		return (0);
	while (ft_isspace(*c))
		c++;
	return(c);
}