/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:12:46 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/21 19:09:43 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sequence_size(int pos, int size, int *tab)
{
	int	seq;
	int	last_nb;

	seq = 1;
	last_nb = tab[pos++];
	while (pos < size)
	{
		if (tab[pos] > last_nb)
		{
			last_nb = tab[pos];
			seq++;
		}
		pos++;
	}
	printf("tab[pos]:%d\nlast_nb:%d\nseq:%d\n\n", tab[pos - 1], last_nb, seq);
	return (seq);
}

int	longest_sequence(t_tab *tab)
{
	int	seq[tab->size]; ///forbidden / changer par tableau des target
	int	seq_tmp;
	int	i;

	seq[0] = 0;
	i = 0;
	while (i < tab->size)
	{
		seq_tmp = sequence_size(i, tab->size, tab->tmp);
		printf("\n%d %d\n\n", seq[0], seq_tmp);
		if (seq_tmp > seq[0])
		{
			seq[0] = seq_tmp;
			seq[1] = i;
		}
		i++;
	}
	return (seq[1]);
}

int	solve(t_tab *tab, t_stack *stack, t_move *move)
{
	int	pos;

	(void)stack;
	(void)move;
	if (init_stack(tab, stack) == -1)
		return (-1);
	pos = longest_sequence(tab);
	printf("position of longest sequence : %d\n", pos);
	return (0);
}
