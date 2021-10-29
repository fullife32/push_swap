/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:04:15 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/29 17:40:25 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_four(t_stack *stack)
{
	push_smallest(stack, 0);
	if (is_stack_sorted(stack->first_a, 0) == 0)
		stack_three(stack);
	do_push(stack, MOVE_PA);
}
