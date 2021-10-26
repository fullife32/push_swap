/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:32:40 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/26 17:21:10 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		sort;
	t_tab	tab;
	t_stack	stack;
	t_pos	pos;
	t_move	move;

	tab = (t_tab){0, NULL, NULL, (t_seq){0, NULL, NULL}};
	stack = (t_stack){0, 0, 0, NULL, NULL, NULL, NULL};
	pos = (t_pos){0, 0, -1, -1, 0, 0, 0, 0};
	move = (t_move){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	if (ac < 2) /// Return error if no num ?
		return (0);
	if (initial_check(av, &tab) == -1)
		return (error(&tab, &stack));
	sort = first_sort(av, &tab);
	if (sort == -1)
		return (error(&tab, &stack));
	else if (sort == 1)
		return (free_push_swap(&tab, &stack));
	if (solve(&tab, &stack, &pos, &move) == -1) /// free pendant la fonction create_stack si malloc fail
		return (error(&tab, &stack));
	return (free_push_swap(&tab, &stack));
}
