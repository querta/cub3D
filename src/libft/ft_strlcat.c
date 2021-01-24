/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:41:43 by mmonte            #+#    #+#             */
/*   Updated: 2020/11/05 14:45:26 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size;
	size_t	len;
	size_t	k;

	len = 0;
	k = 0;
	while (dst[len] && len < dstsize)
		len++;
	size = len;
	while (src[k] && len + 1 < dstsize)
		dst[len++] = src[k++];
	if (size < dstsize)
		dst[len] = '\0';
	return (size + ft_strlen((char *)src));
}
