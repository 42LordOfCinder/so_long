/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:09:26 by gmassoni          #+#    #+#             */
/*   Updated: 2024/02/01 01:14:31 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **lst)
{
	if (!lst || !(*lst))
		return ;
	if ((*lst)->next)
		ft_lstfree((&(*lst)->next));
	free((*lst)->content);
	free(*lst);
	*lst = NULL;
}
