/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:39:12 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/28 19:52:32 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_elem **to, t_elem **from)
{
	t_elem	*elem_push;
	t_elem	*tmp;

	if (*from == NULL)
		return ;
	elem_push = *from;
	if (elem_push->next)
	{
		tmp = elem_push->next->next;
		ft_lstadd_front(from, elem_push->next);
		elem_push->next->next = tmp;
		ft_lstadd_front(to, elem_push);
	}
	else
	{
		tmp = elem_push->next;
		*from = tmp;
		ft_lstadd_front(to, elem_push);
	}
}

void	do_push(t_stack *stack, int move)
{
	if (move == MOVE_PA && stack->size_b > 0)
	{
		push(&stack->first_a, &stack->first_b);
		stack->size_a++;
		stack->size_b--;
	}
	else if (move == MOVE_PB && stack->size_a > 0)
	{
		push(&stack->first_b, &stack->first_a);
		stack->size_a--;
		stack->size_b++;
	}
}
