/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:42:15 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/19 14:36:01 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_sort(char **av, t_tab *tab)
{
	if (create_tab(av, tab) == -1)
		return (-1);
	insertion_sort(tab);
	for (int a = 0; a < tab->size; a++)
		printf("%d : %d\n", a, tab->tmp_tab[a]);
	printf("\n");
	for (int a = 0; a < tab->size; a++)
		printf("%d : %d\n", a, tab->sort_tab[a]);
	return (0);
}
