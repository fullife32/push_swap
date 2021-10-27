/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:41:06 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 23:08:29 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	insertion_sort(t_tab *tab)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (i < tab->size - 1)
	{
		if (tab->sort[i + 1] < tab->sort[i])
		{
			j = i;
			x = tab->sort[j + 1];
			while (j > -1 && x < tab->sort[j])
			{
				tab->sort[j + 1] = tab->sort[j];
				j--;
			}
			tab->sort[j + 1] = x;
		}
		i++;
	}
}
