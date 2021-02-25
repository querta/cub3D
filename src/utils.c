/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:02:28 by mmonte            #+#    #+#             */
/*   Updated: 2021/02/25 17:22:39 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_isnumstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return(0);
		i++;
	}
	return (1);
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

int arrsize(char **arr)
{
	int size;

	size = 0;
	while (arr[size])
		size++;
	return (size);
}

void freearr(char **arr)
{
	int i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}