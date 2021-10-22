/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:42:15 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/22 14:36:50 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_tab *tab)
{
	int	i;

	i = 0;
	if (tab->size == 1)
		return (1);
	while (i < tab->size - 1 && tab->unsort[i] < tab->unsort[i + 1])
		i++;
	if (i == tab->size - 1)
		return (1);
	return (0);
}

int	first_sort(char **av, t_tab *tab)
{
	if (create_tab(av, tab) == -1)
		return (-1);
	if (is_sorted(tab) == 1)
		return (1);
	tab->sort = tab_alloc(tab->size);
	if (tab->sort == NULL)
		return (-1);
	tab->sort = tabdup(tab->sort, tab->unsort, tab->size);
	insertion_sort(tab);
	if (double_num(tab) == -1)
		return (-1);
	// printf("UNSORTED\n");
	// for (int a = 0; a < tab->size; a++)
	// 	printf("%d : %d\n", a, tab->unsort[a]);
	// printf("SORTED\n");
	// for (int a = 0; a < tab->size; a++)
	// 	printf("%d : %d\n", a, tab->sort[a]);
	return (0);
}
