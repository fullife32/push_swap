/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_loop_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:40:30 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 21:52:09 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_seq *seq, t_tab *tab, t_stack *stack)
{
	int	i;
	int	rotate;

	i = 0;
	set_push_elem(tab->size, seq->size, seq->lis, stack->first_a);
	while (i < tab->size - seq->size)
	{
		rotate = next_elem_to_push(stack->first_a);
		while (rotate > 0)
		{
			do_rotate(stack, MOVE_RA);
			rotate--;
		}
		do_push(stack, MOVE_PB);
		i++;
	}
}
