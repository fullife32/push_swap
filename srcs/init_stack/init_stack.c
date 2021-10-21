/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:10:04 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/20 18:03:21 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *stack)
{
	printf("Stack A\n");
	if (stack->first_a)
	{
		for (t_elem *tmp = stack->first_a; tmp; tmp = tmp->next)
			printf("%p : %d -> %d\n", tmp, tmp->pos, tmp->target);
	}
	else
		printf("Empty\n");
	printf("\nStack B\n");
	if (stack->first_b)
	{
		for (t_elem *tmp = stack->first_b; tmp; tmp = tmp->next)
			printf("%p : %d -> %d\n", tmp, tmp->pos, tmp->target);
	}
	else
		printf("Empty\n");
}

int	init_stack(t_tab *tab, t_stack *stack)
{
	stack->a = create_stack(tab, stack);
	if (stack->a == NULL)
		return (-1);
	stack->first_a = stack->a;
	target_stack(tab, stack->first_a);
	// swap(&stack->first_a, stack->size_a);
	print_stacks(stack);
	for (int j = 0; j < 5; j++)
	{
		printf("\nPUSH TO B\n\n");
		push(&stack->first_a, &stack->first_b);
		print_stacks(stack);
	}
	for (int j = 0; j < 5; j++)
	{
		printf("\nPUSH TO A\n\n");
		push(&stack->first_b, &stack->first_a);
		print_stacks(stack);
	}
	return (0);
}
