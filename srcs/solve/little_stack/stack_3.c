/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:04:11 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/29 17:25:51 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_three_else(t_stack *stack)
{
	t_elem	*elem;

	elem = stack->first_a;
	if (elem->target < elem->next->next->target)
	{
		do_swap(stack, MOVE_SA);
		do_rotate(stack, MOVE_RA);
	}
	else
		do_reverse_rotate(stack, MOVE_RRA);
}

void	stack_three(t_stack *stack)
{
	t_elem	*elem;

	elem = stack->first_a;
	if (elem->target > elem->next->target)
	{
		if (elem->next->target < elem->next->next->target)
		{
			if (elem->target < elem->next->next->target)
				do_swap(stack, MOVE_SA);
			else
				do_rotate(stack, MOVE_RA);
		}
		else
		{
			do_swap(stack, MOVE_SA);
			do_reverse_rotate(stack, MOVE_RRA);
		}
	}
	else
		stack_three_else(stack);
}
