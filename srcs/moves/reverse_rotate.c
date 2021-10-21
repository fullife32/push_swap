/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:37:28 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/20 17:56:33 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_elem **first, int  size)
{
    t_elem  *tmp;

    if (*first == NULL || size < 2)
        return ;
    if (size == 2)
    {
        swap(first, size);
        return ;
    }
    tmp = *first;
    while (tmp->next->next)
        tmp = tmp->next;
    ft_lstadd_front(first, tmp->next);
    tmp->next = NULL;
}

void    double_reverse_rotate(t_stack *stack)
{
    reverse_rotate(&stack->first_a, stack->size_a);
    reverse_rotate(&stack->first_b, stack->size_b);
}

