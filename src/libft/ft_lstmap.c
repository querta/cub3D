/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:37:03 by mmonte            #+#    #+#             */
/*   Updated: 2020/11/09 17:41:53 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elemnew;
	t_list	*lstnew;

	if (!lst || !f)
		return (NULL);
	lstnew = ft_lstnew((*f)(lst->content));
	if (!lstnew)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		elemnew = ft_lstnew((*f)(lst->content));
		if (!elemnew)
			ft_lstclear(&lstnew, del);
		ft_lstadd_back(&lstnew, elemnew);
		lst = lst->next;
	}
	return (lstnew);
}
