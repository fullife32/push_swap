/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:12:46 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 14:42:57 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *stack) //delete
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

int	solve(t_tab *tab, t_stack *stack, t_pos *pos, t_move *move)
{
	if (init_stack(tab, stack) == -1)
		return (-1);
	if (push_to_b(&tab->seq, tab, stack) == -1)
		return (-1);
	push_to_a(stack, pos, move);
	return (0);
}
