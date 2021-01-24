/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:16:09 by mmonte            #+#    #+#             */
/*   Updated: 2021/01/20 17:46:14 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printitoa(char *s, long long n, int i, int base)
{
	char *alpha;

	alpha = "0123456789abcdef";
	if (n / base)
		ft_printitoa(s, (n / base), i - 1, base);
	s[i] = alpha[n % base];
}

char		*ft_itoa_base(long long n, int base)
{
	char		*str;
	int			size;
	long long	i;

	i = n;
	size = 0;
	if (i <= 0)
		size = 1;
	while (n)
	{
		n /= base;
		size++;
	}
	if ((str = malloc(size + 1)))
	{
		if (i < 0)
		{
			str[0] = '-';
			i *= -1;
		}
		ft_printitoa(str, i, size - 1, base);
		str[size] = '\0';
		return (str);
	}
	return (NULL);
}
