/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:38:04 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/20 10:21:54 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_elem **lst)
{
	t_elem	*list;
	t_elem	*nxt;

	if (!lst)
		return ;
	list = *lst;
	while (list != NULL)
	{
		nxt = list->next;
		ft_lstdelone(list);
		list = nxt;
	}
	*lst = NULL;
}
