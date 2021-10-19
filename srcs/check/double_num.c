/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:10:20 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/19 16:17:54 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_num(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->size - 1)
	{
		if (tab->sort_tab[i] == tab->sort_tab[i + 1])
			return (-1);
		i++;
	}
	return (0);
}
