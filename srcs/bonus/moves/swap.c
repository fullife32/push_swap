/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:39:05 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 23:12:25 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_elem **first, int size)
{
	t_elem	*elem_tmp;
	int		target_tmp;

	if (*first == NULL || size < 2)
		return ;
	elem_tmp = *first;
	target_tmp = elem_tmp->next->target;
	elem_tmp->next->target = elem_tmp->target;
	elem_tmp->target = target_tmp;
}

void	double_swap(t_stack *stack)
{
	swap(&stack->first_a, stack->size_a);
	swap(&stack->first_b, stack->size_b);
}

void	do_swap(t_stack *stack, int move)
{
	if (move == MOVE_SA)
		swap(&stack->first_a, stack->size_a);
	else if (move == MOVE_SB)
		swap(&stack->first_b, stack->size_b);
	else if (move == MOVE_SS)
		double_swap(stack);
}
