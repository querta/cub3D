/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:05:46 by mmonte            #+#    #+#             */
/*   Updated: 2020/11/02 03:47:43 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	unsigned long long	num;
	int					i;
	int					sign;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (unsigned long long)(num * 10 + str[i] - '0');
		if (num > 9223372036854775807 && sign == 1)
			return (-1);
		if (num > 9223372036854775807 && sign == -1)
			return (0);
		i++;
	}
	return ((int)(sign * num));
}
