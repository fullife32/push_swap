/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:46:14 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 23:36:25 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	main(int ac, char **av)
{
	char	*line;
	t_tab	tab;
	t_stack stack;

	line = NULL;
	tab = (t_tab){0, NULL, NULL};
	stack = (t_stack){0, 0, NULL, NULL, NULL, NULL};
	if (ac < 2) // quit si un seul chiffre ?
		return (0);
	if (check_args(av, &tab) == -1)
		return (error(&tab, &stack));
	first_sort(av, &tab);
	if (init_stack(&tab, &stack) == -1)
		return (-1);
	print_stacks(&stack);
	// while (get_next_line(1, &line) != 0)
	// {
		
	// }
	if (is_stack_sorted(stack.first_a, stack.size_b) == 1)
		write(1, OK, 3);
	else
		write(1, KO, 3);
	return (free_push_swap(&tab, &stack));
}