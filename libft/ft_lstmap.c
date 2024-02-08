/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:11:00 by gmassoni          #+#    #+#             */
/*   Updated: 2023/11/06 16:43:36 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*save;

	new_lst = NULL;
	if (del && f)
	{
		while (lst)
		{
			save = ft_lstnew((*f)(lst->content));
			if (!save)
				ft_lstclear(&lst, del);
			ft_lstadd_back(&new_lst, save);
			lst = lst->next;
		}
	}
	return (new_lst);
}
