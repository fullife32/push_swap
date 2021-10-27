/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_loop_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:40:30 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 03:43:49 by eassouli         ###   ########.fr       */
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

void	set_push_elem(int size, int lis_size, int *lis, t_elem *elem)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (is_target(i, lis_size, lis) == 0)
		{
			elem->push = 1;
		}
		i++;
		elem = elem->next;
	}
}

int	next_elem_to_push(int size, t_elem *elem)
{
	int	i;
	int	first;
	int	last;
	(void)size;

	i = 0;
	first = -1;
	last = -1;
	while (elem)
	{
		if (first == -1 && elem->push == 1)
			first = i;
		if (elem->push == 1)
			last = i;
		i++;
		elem = elem->next;
	}
	if (first <= size - last)
		return (first);
	return (-(size - last));
}

int	push_to_b(t_seq *seq, t_tab *tab, t_stack *stack)
{
	int		i;
	int		rotate;

	if (longest_sequence(seq, tab, tab->size) == -1)
		return (-1);
	i = 0;
	set_push_elem(tab->size, seq->size, seq->lis, stack->first_a);
	for (t_elem *elem = stack->first_a; elem; elem = elem->next)
	while (i < tab->size - seq->size)
	{
		rotate = next_elem_to_push(tab->size - i, stack->first_a);
		while (rotate > 0)
		{
			do_rotate(stack, MOVE_RA);
			rotate--;
		}
		while (rotate < 0)
		{
			do_reverse_rotate(stack, MOVE_RRA);
			rotate++;
		}
		do_push(stack, MOVE_PB);
		i++;
	}
	return (0);
}

// int	push_to_b(t_seq *seq, t_tab *tab, t_stack *stack)
// {
// 	int	i;
// 	t_elem  *elem;
// 	if (longest_sequence(seq, tab, tab->size) == -1)
// 		return (-1);
// 	i = 0;
// 	while (i < tab->size)
// 	{
// 		elem = stack->first_a; // Utile ?
// 		if (is_target(i, seq->size, seq->lis) == 0)
// 			do_push(stack, MOVE_PB);
// 		else
// 			do_rotate(stack, MOVE_RA);
// 		i++;
// 	}
// 	return (0);
// }