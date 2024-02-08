/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:50:21 by gmassoni          #+#    #+#             */
/*   Updated: 2023/11/06 16:01:26 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (lst && del)
	{
		if (lst[0]->next)
			ft_lstclear(&(lst[0]->next), del);
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
}
