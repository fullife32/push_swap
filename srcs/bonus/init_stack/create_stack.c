/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:42:27 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 23:29:21 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_elem	*init_elem(void)
{
	t_elem	*elem;

	elem = ft_lstnew();
	return (elem);
}

t_elem	*create_stack(t_tab *tab, t_stack *stack)
{
	int		i;
	t_elem	*first;
	t_elem	*elem;

	i = 1;
	elem = init_elem();
	if (elem == NULL)
		return (NULL);
	first = elem;
	while (i < tab->size)
	{
		elem->next = init_elem();
		if (elem->next == NULL)
		{
			stack->first_a = first;
			return (NULL);
		}
		elem = elem->next;
		i++;
	}
	stack->size_a = tab->size;
	return (first);
}
