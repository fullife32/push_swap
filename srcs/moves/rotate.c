/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:39:09 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/22 16:21:58 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_elem **first, int size)
{
	t_elem	*elem_rotate;
	t_elem	*new_first;
	t_elem	*tmp;

	if (*first == NULL || size < 2)
		return ;
	if (size == 2)
	{
		swap(first, size);
		return ;
	}
	elem_rotate = *first;
	new_first = elem_rotate->next;
	tmp = elem_rotate->next->next;
	elem_rotate->next = NULL;
	ft_lstadd_front(first, new_first);
	new_first->next = tmp;
	ft_lstadd_back(first, elem_rotate);
}

void	double_rotate(t_stack *stack)
{
	rotate(&stack->first_a, stack->size_a);
	rotate(&stack->first_b, stack->size_b);
}


void	do_rotate(t_stack *stack, int move)
{
	if (move == MOVE_RA)
	{
		rotate(&stack->first_a, stack->size_a);
		write(1, "ra\n", 3);
	}
	else if (move == MOVE_RB)
	{
		rotate(&stack->first_b, stack->size_b);
		write(1, "rb\n", 3);
	}
	else if (move == MOVE_RR)
	{
		double_rotate(stack);
		write(1, "rr\n", 3);
	}
}
