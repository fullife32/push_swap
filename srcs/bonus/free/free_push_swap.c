/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:05:34 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/28 19:30:07 by eassouli         ###   ########.fr       */
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

void	free_inst(char **line)
{
	if (*line)
		free(*line);
	*line = NULL;
}

int	free_push_swap(t_tab *tab, t_stack *stack, t_inst *inst)
{
	free_tab(tab->sort);
	free_tab(tab->unsort);
	free_stack(&stack->first_a);
	free_stack(&stack->first_b);
	free_inst(&inst->line);
	return (0);
}
