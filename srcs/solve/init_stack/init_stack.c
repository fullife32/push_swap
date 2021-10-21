/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:10:04 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/21 19:11:03 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *stack)
{
	printf("----- Stack A -----\n");
	if (stack->first_a)
	{
		for (t_elem *tmp = stack->first_a; tmp; tmp = tmp->next)
			printf("%p : new pos -> %d\n", tmp, tmp->target);
	}
	else
		printf("Empty\n");
	printf("\n----- Stack B -----\n");
	if (stack->first_b)
	{
		for (t_elem *tmp = stack->first_b; tmp; tmp = tmp->next)
			printf("%p : new pos -> %d\n", tmp, tmp->target);
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
	// push(&stack->first_a, &stack->first_b);
	// print_stacks(stack);
	// for (int j = 0; j < 3; j++)
	// {
	// 	printf("\n===== PUSH B =====\n\n");
	// 	push(&stack->first_a, &stack->first_b);
	// 	if (stack->size_a > 0)
	// 		stack->size_a--;
	// 	stack->size_b++;
	// 	print_stacks(stack);
	// }
	// for (int j = 0; j < 5; j++)
	// {
	// 	printf("\n===== REVERSE ROTATE A && B =====\n\n");
	// 	double_reverse_rotate(stack);
	// 	print_stacks(stack);
	// }
	// for (int j = 0; j < 5; j++)
	// {
	// 	printf("\nROTATE B\n\n");
	// 	rotate(&stack->first_b, stack->size_b);
	// 	print_stacks(stack);
	// }
	return (0);
}
