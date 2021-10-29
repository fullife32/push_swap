/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:12:46 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/29 17:48:04 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solve(t_tab *tab, t_stack *stack, t_pos *pos, t_move *move)
{
	if (init_stack(tab, stack) == -1)
		return (-1);
	if (longest_sequence(&tab->seq, tab, tab->size) == -1)
		return (-1);
	if (stack->size_a >= 3 && stack->size_a <= 5)
		little_stack(stack);
	else
	{
		push_to_b(&tab->seq, tab, stack);
		push_to_a(stack, pos, move);
	}
	return (0);
}
