/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:16:23 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/20 14:25:13 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	target_pos(t_tab *tab, int pos)
{
	int	i;

	i = 0;
	while (i < tab->size)
	{
		if (tab->tmp[pos] == tab->sort[i])
			return (i);
		i++;
	}
	return (0);
}

void	target_stack(t_tab *tab, t_elem *elem)
{
	int	i;

	i = 0;
	while (elem)
	{
		elem->target = target_pos(tab, i);
		elem = elem->next;
		i++;
	}
}
