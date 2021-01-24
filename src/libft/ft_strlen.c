/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:58:06 by mmonte            #+#    #+#             */
/*   Updated: 2020/11/12 15:52:01 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t		ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	if (str)
	{
		while (str[len])
			len++;
	}
	return (len);
}
