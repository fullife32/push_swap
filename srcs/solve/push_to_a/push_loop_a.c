/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_loop_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:01:17 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/26 15:56:40 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_moves(int pos_a, int pos_b, int size_a, int size_b, t_move *move)
{

}

void	exec_moves(t_stack *stack, t_move *move)
{
	
}

void	find_final_moves(int size_a, t_elem *first_a, t_move *move)
{
	int		i;
	t_elem	*elem;

	i = 0;
	elem = first_a;
	while (elem->target != 0)
	{
		i++;
		elem = elem->next;
	}
	if (i == 0)
		return;
	if (i < size_a / 2)
		move->ra = i;
	else
		move->rra = size_a - i;
}

void	push_to_a(t_stack *stack, t_move *move)
{
	int		pos_b;
	int		old_pos_a;
	int		pos_a;
	t_elem	*stack_b;

	old_pos_a = -1;
	while (stack_is_sorted(&stack->first_b, stack->size_b) == 0)
	{
		pos_b = 0;
		stack_b = &stack->first_b;
		while (stack_b)
		{
			pos_a = dist_to_a(&stack->first_a, stack_b, stack->size_a, stack->size_b);
			if (pos_a < old_pos_a || old_pos_a == -1)
				old_pos_a = pos_a;
			stack_b = stack_b->next;
			pos_b++;
		}
		reset_moves(move);
		if (stack->first_b == NULL)
			find_final_moves(stack->size_a, &stack->first_a, move);
		else
			find_moves(old_pos_a, pos_b, stack->size_a, stack->size_b, move);
		exec_moves(stack, move);
	}
}
