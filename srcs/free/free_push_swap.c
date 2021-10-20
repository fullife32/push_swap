/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:05:34 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/20 12:09:16 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_elem **first)
{
	if (*first)
		ft_lstclear(first);
}

int	free_push_swap(t_tab *tab, t_stack *stack)
{
	if (tab->sort_tab)
		free(tab->sort_tab);
	tab->sort_tab = NULL;
	if (tab->tmp_tab)
		free(tab->tmp_tab);
	tab->tmp_tab = NULL;
	free_stack(&stack->first_a);
	free_stack(&stack->first_b);
	return (0);
}
