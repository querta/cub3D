/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:16:09 by mmonte            #+#    #+#             */
/*   Updated: 2020/11/07 21:52:45 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printitoa(char *s, long n, int i)
{
	if (n / 10)
		ft_printitoa(s, (n / 10), i - 1);
	s[i] = (n % 10) + '0';
}

char		*ft_itoa(int n)
{
	char	*str;
	int		size;
	long	i;

	i = n;
	size = 0;
	if (i <= 0)
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	if ((str = malloc(size + 1)))
	{
		if (i < 0)
		{
			str[0] = '-';
			i *= -1;
		}
		ft_printitoa(str, i, size - 1);
		str[size] = '\0';
		return (str);
	}
	return (NULL);
}
