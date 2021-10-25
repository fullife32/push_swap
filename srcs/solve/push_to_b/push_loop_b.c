/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_loop_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:40:30 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/25 17:09:42 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_target(int target, int size, int *lis)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (target == lis[i])
			return (1);
		i++;
	}
	return (0);
}

int	push_to_b(t_seq *seq, t_tab *tab, t_stack *stack)
{
	int	i;
	t_elem	*elem;

	if (longest_sequence(seq, tab, tab->size) == -1)
		return (-1);
	i = 0;
	elem = stack->first_a;
	while (elem)
	{
		if (is_target(i, seq->size, seq->lis) == 0)
		{
			do_push(stack, MOVE_PB);
			elem = stack->first_a;
		}
		else
			do_rotate(stack, MOVE_RA);
		i++;
		elem = elem->next;
	}
	return (0);
}