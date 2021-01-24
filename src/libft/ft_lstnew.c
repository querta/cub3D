/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 22:10:48 by mmonte            #+#    #+#             */
/*   Updated: 2020/11/07 22:25:31 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*s_list;

	s_list = malloc(sizeof(t_list));
	if (s_list)
	{
		s_list->content = content;
		s_list->next = NULL;
	}
	return (s_list);
}
