/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:17:49 by mmonte            #+#    #+#             */
/*   Updated: 2020/10/30 18:17:52 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;

	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	while (n--)
	{
		*dptr = *sptr++;
		if (*dptr == (unsigned char)c)
			return (dptr + 1);
		dptr++;
	}
	return (NULL);
}
