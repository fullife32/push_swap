/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:43:33 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/26 15:12:31 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_elem **first, int size)
{
	int		old_target;
	t_elem	*elem;

	if (*first == NULL || size != 0)
		return (0);
	elem = *first;
	old_target = elem->target;
	while (elem)
	{
		if (old_target > elem->target)
			return (0);
		old_target = elem->target;
		elem = elem->next;
	}
	return (1);
}
