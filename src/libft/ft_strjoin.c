/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:45:22 by mmonte            #+#    #+#             */
/*   Updated: 2020/11/12 16:34:05 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	k;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	k = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	if ((str = malloc(size + 1)))
	{
		while (s1[k])
			str[i++] = s1[k++];
		k = 0;
		while (s2[k])
			str[i++] = s2[k++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
