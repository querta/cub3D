/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:45:22 by mmonte            #+#    #+#             */
/*   Updated: 2020/11/07 20:09:21 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		size;
	char	*start;
	char	*end;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	while (ft_strchr(set, *start) != NULL && *start != '\0')
		start++;
	end = start + ft_strlen((char *)start);
	while (ft_strchr(set, *end) != NULL && end >= start)
		end--;
	size = end - start;
	if ((str = malloc(size + 2)))
	{
		while (start <= end)
			*str++ = *start++;
		*str = '\0';
		return (str - size - 1);
	}
	return (NULL);
}
