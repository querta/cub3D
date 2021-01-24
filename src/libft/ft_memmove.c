/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:14:23 by mmonte            #+#    #+#             */
/*   Updated: 2020/10/30 21:39:57 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dptr;
	char	*sptr;

	dptr = (char *)dst;
	sptr = (char *)src;
	if (dst || src)
	{
		if (dptr < sptr)
		{
			while (len--)
				*dptr++ = *sptr++;
		}
		else
		{
			dptr += len;
			sptr += len;
			while (len--)
				*--dptr = *--sptr;
		}
	}
	return (dst);
}
