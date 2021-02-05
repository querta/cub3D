/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:02:28 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/05 19:14:22 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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