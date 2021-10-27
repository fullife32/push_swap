/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:18:04 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 15:11:05 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_simple_moves(int size_a, int size_b, t_pos *pos, t_move *move)
{
	if (pos->old_up_a == 1)
		move->ra = pos->old_a;
	else if (pos->old_up_a == 0)
		move->rra = size_a - pos->old_a;
	if (pos->old_up_b == 1)
		move->rb = pos->old_b;
	else if (pos->old_up_b == 0)
		move->rrb = size_b - pos->old_b;
}

void	find_double_moves(t_move *move)
{
	if (move->ra > 0 && move->rb > 0)
	{
		if (move->ra < move->rb)
			move->rr = move->ra;
		else
			move->rr = move->rb;
		move->ra -= move->rr;
		move->rb -= move->rr;
	}
	else if (move->rra > 0 && move->rrb > 0)
	{
		if (move->rra < move->rrb)
			move->rrr = move->rra;
		else
			move->rrr = move->rrb;
		move->rra -= move->rrr;
		move->rrb -= move->rrr;
	}
}

void	find_moves(int size_a, int size_b, t_pos *pos, t_move *move)
{
	find_simple_moves(size_a, size_b, pos, move);
	find_double_moves(move);
	if (size_b > 0)
		move->pa = 1;
}

void	find_final_moves(int size_a, t_elem *first_a, t_move *move)
{
	int		i;
	t_elem	*elem;

	i = 0;
	elem = first_a;
	while (elem->target != 0)
	{
		i++;
		elem = elem->next;
	}
	if (i == 0)
		return ;
	if (i < size_a / 2)
		move->ra = i;
	else
		move->rra = size_a - i;
}
