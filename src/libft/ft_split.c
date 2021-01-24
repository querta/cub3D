/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:52:56 by mmonte            #+#    #+#             */
/*   Updated: 2020/11/14 14:13:28 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_makestr(const char *s, char c, size_t *begin)
{
	size_t	start;
	char	*str;
	size_t	k;

	k = *begin;
	while (s[k] == c)
		k++;
	start = k;
	while (s[k] != c && s[k] != '\0')
		k++;
	str = ft_substr((const char*)s, start, k - start);
	*begin = k;
	return (str);
}

static int		ft_wordcounter(char const *s, char c)
{
	int n;

	n = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if ((*s == c || *(s + 1) == '\0') && *(s + 1) != c)
			n++;
		s++;
	}
	return (n);
}

static void		ft_clear(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}

char			**ft_split(char const *s, char c)
{
	size_t		count;
	size_t		k;
	size_t		i;
	char		**arr;

	k = 0;
	i = 0;
	if (!s)
		return (NULL);
	count = ft_wordcounter(s, c);
	if (!(arr = (char **)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	while (i < count)
	{
		if (!(arr[i] = ft_makestr(s, c, &k)))
		{
			ft_clear(arr);
			free(arr);
		}
		i++;
	}
	arr[i] = 0;
	return (arr);
}
