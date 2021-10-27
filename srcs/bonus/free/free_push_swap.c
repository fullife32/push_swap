/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:05:34 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 23:08:39 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_stack(t_elem **first)
{
	if (*first)
		ft_lstclear(first);
}

void	free_tab(int *tab)
{
	if (tab)
		free(tab);
	tab = NULL;
}

int	free_push_swap(t_tab *tab, t_stack *stack)
{
	free_tab(tab->sort);
	free_tab(tab->unsort);
	free_stack(&stack->first_a);
	free_stack(&stack->first_b);
	return (0);
}
