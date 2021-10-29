/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:04:20 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/29 17:59:19 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_five(t_stack *stack)
{
	push_smallest(stack, 0);
	if (is_stack_sorted(stack->first_a, 0) == 0)
		push_smallest(stack, 1);
	if (is_stack_sorted(stack->first_a, 0) == 0)
		stack_three(stack);
	do_push(stack, MOVE_PA);
	if (is_stack_sorted(stack->first_a, stack->size_b) == 0)
		do_push(stack, MOVE_PA);
}
