/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:02:11 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 15:08:03 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_target(t_elem *elem, int size)
{
	int	i;
	int	biggest_target;
	int	biggest_index;

	i = 0;
	biggest_target = -1;
	while (elem)
	{
		if (elem->target > biggest_target)
		{
			biggest_target = elem->target;
			biggest_index = i;
		}
		i++;
		elem = elem->next;
	}
	if (biggest_index == size - 1)
		return (0);
	return (biggest_index + 1);
}

void	find_pos_a(int target, t_stack *stack, t_pos *pos)
{
	int		i;
	int		near;
	t_elem	*stack_a;

	i = 0;
	near = -1;
	pos->a = 0;
	stack_a = stack->first_a;
	while (stack_a)
	{
		if ((near == -1 || stack_a->target - target < near)
			&& stack_a->target - target > 0)
		{
			near = stack_a->target - target;
			pos->a = i;
		}
		i++;
		stack_a = stack_a->next;
	}
	if (near == -1)
		pos->a = biggest_target(stack->first_a, stack->size_a);
}

void	keep_best_pos(int size_a, int size_b, t_pos *pos)
{
	int	number_of_moves;
	int	old_number_of_moves;

	dist_to_a(size_a, size_b, pos);
	number_of_moves = pos->dist_a + pos->dist_b;
	old_number_of_moves = pos->old_dist_a + pos->old_dist_b;
	if (pos->old_a == -1 || number_of_moves < old_number_of_moves)
	{
		pos->old_a = pos->a;
		pos->old_b = pos->b;
		pos->old_dist_a = pos->dist_a;
		pos->old_dist_b = pos->dist_b;
		pos->old_up_a = pos->up_a;
		pos->old_up_b = pos->up_b;
	}
}
