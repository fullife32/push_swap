/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:32:40 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/20 12:18:05 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_tab	tab;
	t_stack	stack;
	t_move	move;

	tab = (t_tab){0, NULL, NULL};
	stack = (t_stack){0, 0, NULL, NULL, NULL, NULL};
	if (ac < 2) /// Return error if no num ?
		return (0);
	if (initial_check(av, &tab) == -1)
		return (error(&tab, &stack));
	if (first_sort(av, &tab) == -1)
		return (error(&tab, &stack));
	if (tab.size == 1)
		return (free_push_swap(&tab, &stack));
	stack.a = create_stack(&tab, &stack);
	if (stack.a == NULL)
		return (error(&tab, &stack)); /// free pendant la fonction create_stack si malloc fail
	stack.first_a = stack.a;
	/// run_algo(&tab, &stack, &move);
	return (free_push_swap(&tab, &stack));
}
