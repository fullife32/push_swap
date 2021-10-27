/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_sequence.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:48:33 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 14:49:44 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_tab(t_seq *seq, t_tab *tab)
{
	int	i;
	int	tmp;

	while (tab->unsort[0] != tab->sort[0])
	{
		i = 0;
		tmp = tab->unsort[0];
		while (i < tab->size - 1)
		{
			tab->unsort[i] = tab->unsort[i + 1];
			i++;
		}
		tab->unsort[i] = tmp;
		seq->shift++;
	}
}

void	unshift_seq(t_seq *seq, int size)
{
	int	i;

	i = 0;
	if (seq->shift == 0)
		return ;
	while (i < seq->size)
	{
		if (seq->lis[i] + seq->shift > size - 1)
			seq->lis[i] = seq->shift + seq->lis[i] - size;
		else
			seq->lis[i] = seq->lis[i] + seq->shift;
		i++;
	}
}
