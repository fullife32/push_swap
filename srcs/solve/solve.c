/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:12:46 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/22 17:01:48 by eassouli         ###   ########.fr       */
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
	dist_to_a(stack->first_a, stack->first_b, stack->size_a, stack->size_b);
	// while (stack_is_sorted(&stack->first_a, stack->size_b) == 0)
	// {
		
	// }
	// tab->seq.size = tab->size;
	// tabdup(tab->seq.a, tab->unsort, tab->size);
	// printf("longest sequence size : %d\nsequence :\n", tab->seq.size);
	// for (int i = 0; i < tab->seq.size; i++)
	// 	printf("%d ", tab->seq.a[i]);
	// printf("\n");
	return (0);
}
