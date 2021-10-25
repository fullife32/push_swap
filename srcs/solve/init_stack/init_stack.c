/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:10:04 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/25 16:52:31 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_tab *tab, t_stack *stack)
{
	stack->a = create_stack(tab, stack);
	if (stack->a == NULL)
		return (-1);
	stack->first_a = stack->a;
	target_stack(tab, stack->first_a);
	return (0);
}
