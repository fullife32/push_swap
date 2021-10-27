/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_loop_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:01:17 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 15:02:37 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stack *stack, t_pos *pos, t_move *move)
{
	t_elem	*stack_b;

	while (is_stack_sorted(stack->first_a, stack->size_b) == 0)
	{
		stack_b = stack->first_b;
		while (stack_b)
		{
			find_pos_a(stack_b->target, stack, pos);
			keep_best_pos(stack->size_a, stack->size_b, pos);
			stack_b = stack_b->next;
			pos->b++;
		}
		reset_moves(move);
		if (stack->first_b == NULL)
			find_final_moves(stack->size_a, stack->first_a, move);
		else
			find_moves(stack->size_a, stack->size_b, pos, move);
		exec_moves(stack, move);
		reset_pos(pos);
	}
}
