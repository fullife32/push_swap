/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:39:05 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/20 18:03:38 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_elem **first, int size)
{
	t_elem	*elem_tmp;
	int		target_tmp;

	target_tmp = 0;
	if (*first && size > 1)
	{
		elem_tmp = *first;
		target_tmp = elem_tmp->next->target;
		elem_tmp->next->target = elem_tmp->target;
		elem_tmp->target = target_tmp;
	}
}

void	double_swap(t_stack *stack)
{
	swap(&stack->first_a, stack->size_a);
	swap(&stack->first_b, stack->size_b);
}
