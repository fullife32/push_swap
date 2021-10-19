/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:41:06 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/19 14:50:04 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_tab *tab)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (i < tab->size - 1)
	{
		if (tab->sort_tab[i + 1] < tab->sort_tab[i])
		{
			j = i;
			x = tab->sort_tab[j + 1];
			while (j > -1 && x < tab->sort_tab[j])
			{
				tab->sort_tab[j + 1] = tab->sort_tab[j];
				j--;
			}
			tab->sort_tab[j + 1] = x;
		}
		i++;
	}
}
