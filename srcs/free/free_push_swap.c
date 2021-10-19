/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:05:34 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/19 14:18:09 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_push_swap(t_tab *tab)
{
	if (tab->sort_tab)
		free(tab->sort_tab);
	tab->sort_tab = NULL;
	if (tab->tmp_tab)
		free(tab->tmp_tab);
	tab->tmp_tab = NULL;
}
