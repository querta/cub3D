/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:03:16 by mmonte            #+#    #+#             */
/*   Updated: 2020/11/07 23:03:31 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	t_list	*lstlast;

	if (!lst)
		return (lst);
	while (lst)
	{
		lstlast = lst;
		lst = lst->next;
	}
	return (lstlast);
}
