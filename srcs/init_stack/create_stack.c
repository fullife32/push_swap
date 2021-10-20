/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:42:27 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/20 14:07:48 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*init_elem(int pos)
{
	t_elem	*elem;

	elem = ft_lstnew();
	elem->pos = pos;
	return (elem);
}

t_elem	*create_stack(t_tab *tab, t_stack *stack)
{
	int	i;
	t_elem	*first;
	t_elem	*elem;

	(void)stack;
	i = 1;
	elem = init_elem(0);
	if (elem == NULL)
		return (NULL);
	first = elem;
	while (i < tab->size)
	{
		elem->next = init_elem(i);
		if (elem->next == NULL)
		{
			stack->first_a = first;
			return (NULL);
		}
		elem = elem->next;
		i++;
	}
	return (first);
}
