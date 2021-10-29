/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:03:56 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/29 18:26:22 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_smallest(t_stack *stack, int smallest)
{
	int		i;
	t_elem	*elem;

	i = 0;
	elem = stack->first_a;
	while (elem->target != smallest)
	{
		i++;
		elem = elem->next;
	}
	while (i <= stack->size_a / 2 && i > 0)
	{
		do_rotate(stack, MOVE_RA);
		i--;
	}
	while (i > stack->size_a / 2 && i < stack->size_a)
	{
		do_reverse_rotate(stack, MOVE_RRA);
		i++;
	}
	if (is_stack_sorted(stack->first_a, 0) == 0)
		do_push(stack, MOVE_PB);
}

void	little_stack(t_stack *stack)
{
	if (stack->size_a == 3)
		stack_three(stack);
	else if (stack->size_a == 4)
		stack_four(stack);
	else
		stack_five(stack);
}
