/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:12:46 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/22 16:27:39 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solve(t_tab *tab, t_stack *stack, t_move *move)
{
	(void)move;

	if (init_stack(tab, stack) == -1)
		return (-1);
	if (longest_sequence(&tab->seq, tab) == -1)
		return (-1);
	while (stack_is_sorted(&stack->first_a, stack->size_b) == 0)
	{
		do_push(stack, MOVE_PB);
		do_rotate(stack, MOVE_RA);
		do_push(stack, MOVE_PA);
		do_reverse_rotate(stack, MOVE_RRA);
	}
	// tab->seq.size = tab->size;
	// tabdup(tab->seq.a, tab->unsort, tab->size);
	// printf("longest sequence size : %d\nsequence :\n", tab->seq.size);
	// for (int i = 0; i < tab->seq.size; i++)
	// 	printf("%d ", tab->seq.a[i]);
	// printf("\n");
	return (0);
}
