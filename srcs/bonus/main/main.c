/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:46:14 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/28 21:43:59 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_tab	tab;
	t_stack stack;
	t_inst	inst;

	tab = (t_tab){0, NULL, NULL};
	stack = (t_stack){0, 0, NULL, NULL, NULL, NULL};
	inst = (t_inst){0, NULL};
	if (ac < 2) // quit si un seul chiffre ?
		return (0);
	if (check_args(av, &tab) == -1)
		return (error(&tab, &stack, &inst));
	if (first_sort(av, &tab) == -1)
		return (error(&tab, &stack, &inst));
	if (init_stack(&tab, &stack) == -1)
		return (error(&tab, &stack, &inst));
	if (inst_loop(&stack, &inst) == -1)
		return (error(&tab, &stack, &inst));
	if (is_stack_sorted(stack.first_a, stack.size_b) == 1)
		write(1, OK, 3);
	else
		write(1, KO, 3);
	return (free_push_swap(&tab, &stack, &inst));
}