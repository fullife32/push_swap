/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:36:16 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/26 15:18:42 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	number_of_moves(int index_a, int index_b, int size_a, int size_b)
// {

// }

int	find_a_pos(t_elem *first_a, int size_a, int target)
{
	int		pos;
	t_elem	*stack_a;

	pos = 0;
	(void)size_a;
	stack_a = first_a;
	while (stack_a)
	{
		if (stack_a->target == target - 1)
			return (pos + 1);
		else if (stack_a->target == target + 1)
			return (pos);
		pos++;
		stack_a = stack_a->next;
	}
	return (pos);
}

int	dist_to_a(t_elem *first_a, t_elem *stack_b, int size_a, int size_b)
{
	int		pos_a;
	int		pos_b;
	int		old_number_of_move;
	int		number_of_move;

	(void)size_a;
	(void)size_b;
	if (stack_b == NULL)
		return (-1);
	else if (first_a == NULL)
		return (0);
	pos_a = 0;
	pos_b = 0;
	old_number_of_move = 0;
	number_of_move = 0;
	while (stack_b)
	{
		new_number_of_move = find_a_pos(first_a, size_a, stack_b->target);
		if (new_number_of_move < number_of_move || number_of_move == 0)
			number_of_move = new_number_of_move;
		pos_b++;
		stack_b = stack_b->next;
	}
	return (pos_b);
}
