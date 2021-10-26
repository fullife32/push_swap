/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:57:26 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 01:06:35 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_seq(t_seq *seq, int size)
{
	int	i;

	i = 0;
	seq->lis = tab_alloc(size);
	if (seq->lis == NULL)
		return (-1);
	seq->tmp = tab_alloc(size);
	if (seq->tmp == NULL)
		return (-1);
	while (i < size)
	{
		seq->tmp[i] = 1;
		i++;
	}
	return (0);
}

int	last_nb(int *tab, int size)
{
	int	last;

	last = 0;
	size--;
	while (size >= 0)
	{
		if (tab[size] >= tab[last])
			last = size;
		size--;
	}
	return (last);
}

void	keep_longest(t_seq *seq, int size)
{
	int	j;
	int	last;

	size = last_nb(seq->tmp, size);
	seq->size = seq->tmp[size];
	seq->lis[seq->size - 1] = size;
	last = seq->size;
	j = 1;
	while (j < seq->size)
	{
		if (seq->tmp[size] == last - 1)
		{
			seq->lis[seq->size - j - 1] = size;
			j++;
			last--;
		}
		size--;
	}
}

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

int	longest_sequence(t_seq *seq, t_tab *tab, int size)
{
	int	i;
	int	j;

	if (init_seq(seq, size) == -1)
		return (-1);
	shift_tab(seq, tab);
	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (tab->unsort[j] < tab->unsort[i]
				&& seq->tmp[i] < seq->tmp[j] + 1)
				seq->tmp[i] = seq->tmp[j] + 1;
			j++;
		}
		i++;
	}
	keep_longest(seq, size);
	unshift_seq(seq, size);
	return (0);
}
