/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:40:43 by mmonte            #+#    #+#             */
/*   Updated: 2020/11/13 22:52:17 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *needle, size_t len)
{
	size_t	n;
	size_t	i;

	if (!s && !needle)
		return (NULL);
	n = ft_strlen(needle);
	if (n > len)
		n = len;
	else
		n -= 1;
	ft_strlen(s);
	while (len-- - n)
	{
		i = 0;
		while (s[i] == needle[i] && needle[i])
			i++;
		if (!needle[i])
			return ((char *)s);
		s++;
	}
	return (NULL);
}
