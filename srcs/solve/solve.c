/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:12:46 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/25 17:39:36 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *stack)
{
	printf("----- Stack A ----- %d\n", stack->size_a);
	if (stack->first_a)
	{
		for (t_elem *tmp = stack->first_a; tmp; tmp = tmp->next)
			printf("%p : new pos -> %d\n", tmp, tmp->target);
	}
	else
		printf("Empty\n");
	printf("\n----- Stack B ----- %d\n", stack->size_b);
	if (stack->first_b)
	{
		for (t_elem *tmp = stack->first_b; tmp; tmp = tmp->next)
			printf("%p : new pos -> %d\n", tmp, tmp->target);
	}
	else
		printf("Empty\n");
}

int	solve(t_tab *tab, t_stack *stack, t_move *move)
{
	(void)move;

	if (init_stack(tab, stack) == -1)
		return (-1);
	// print_stacks(stack);
	if (push_to_b(&tab->seq, tab, stack) == -1)
		return (-1);
	// printf("\nsequence : \n");
	// for(int i = 0; i < tab->seq.size; i++)
		// printf("%d\n", tab->seq.lis[i]);
	// printf("sequence size = %d\n", tab->seq.size);
	// print_stacks(stack);
	
	// dist_to_a(stack->first_a, stack->first_b, stack->size_a, stack->size_b);
	// while (stack_is_sorted(&stack->first_a, stack->size_b) == 0)
	// {
		
	// }
	// tab->seq.size = tab->size;
	// tabdup(tab->seq.a, tab->unsort, tab->size);
	// for (int i = 0; i < tab->seq.size; i++)
	// 	printf("%d ", tab->seq.a[i]);
	// printf("\n");
	return (0);
}
