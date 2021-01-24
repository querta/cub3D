/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:29:32 by mmonte            #+#    #+#             */
/*   Updated: 2020/11/07 23:29:35 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lelem;

	if (del || lst || *lst)
	{
		while (lst && *lst)
		{
			lelem = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = lelem;
		}
	}
}
