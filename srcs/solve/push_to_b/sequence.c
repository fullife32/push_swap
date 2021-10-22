/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:57:26 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/22 14:57:45 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	seq_alloc(t_seq *seq, int size)
{
	seq->a = tab_alloc(size);
	if (seq->a == NULL)
		return (-1);
	seq->tmp = tab_alloc(size);
	if (seq->tmp == NULL)
		return (-1);
	return (0);
}

int	sequence_loop(int pos, int size, int *seq, int *tab)
{
	(void)pos;
	(void)size;
	(void)seq;
	(void)tab;
	return (0);
}

int	longest_sequence(t_seq *seq, t_tab *tab)
{
	int	i;

	i = 0;
	if (seq_alloc(seq, tab->size) == -1)
		return (-1);
	while (i < tab->size)
	{
		seq->tmp_size = sequence_loop(i, tab->size, seq->tmp, tab->unsort);
		if (seq->tmp_size > seq->size)
		{
			seq->size = seq->tmp_size;
			seq->a = tabdup(seq->a, seq->tmp, seq->size);
		}
		i++;
	}
	return (seq->size);
}
