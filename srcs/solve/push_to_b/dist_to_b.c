/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:31:15 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 14:32:18 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_target(int target, int size, int *lis)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (target == lis[i])
			return (1);
		i++;
	}
	return (0);
}

void	set_push_elem(int size, int lis_size, int *lis, t_elem *elem)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (is_target(i, lis_size, lis) == 0)
		{
			elem->push = 1;
		}
		i++;
		elem = elem->next;
	}
}

int	next_elem_to_push(t_elem *elem)
{
	int	i;

	i = 0;
	while (elem)
	{
		if (elem->push == 1)
			return (i);
		i++;
		elem = elem->next;
	}
	return (0);
}
