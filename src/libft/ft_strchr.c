/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:26:34 by mmonte            #+#    #+#             */
/*   Updated: 2020/11/08 18:51:52 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		k;
	char	*str;

	str = (char *)s;
	i = 0;
	k = 0;
	while (str[i])
		i++;
	while (k <= i)
	{
		if (str[k] == (char)c)
			return (&(str[k]));
		k++;
	}
	return (NULL);
}
