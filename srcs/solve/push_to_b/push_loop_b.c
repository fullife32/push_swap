/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_loop_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:40:30 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/26 18:17:52 by eassouli         ###   ########.fr       */
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

int	push_to_b(t_seq *seq, t_tab *tab, t_stack *stack) // do reverse if necessary
{
	int		i;
	t_elem	*elem;

	if (longest_sequence(seq, tab, tab->size) == -1)
		return (-1);
	i = 0;
	while (i < tab->size)
	{
		elem = stack->first_a; // Utile ?
		if (is_target(i, seq->size, seq->lis) == 0)
			do_push(stack, MOVE_PB);
		else
			do_rotate(stack, MOVE_RA);
		i++;
	}
	return (0);
}
