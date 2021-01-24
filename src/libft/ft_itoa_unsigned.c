/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:16:09 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/20 16:03:47 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printitoa(char *s, unsigned int n, unsigned int i)
{
	if (n / 10)
		ft_printitoa(s, (n / 10), i - 1);
	s[i] = (n % 10) + '0';
}

char		*ft_itoa_unsigned(unsigned int n)
{
	char			*str;
	unsigned int	size;
	unsigned int	i;

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
		ft_printitoa(str, i, size - 1);
		str[size] = '\0';
		return (str);
	}
	return (NULL);
}
