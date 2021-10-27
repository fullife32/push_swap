/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:17:42 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 14:21:28 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_moves_rotate(t_stack *stack, t_move *move)
{
	while (move->rr > 0)
	{
		do_rotate(stack, MOVE_RR);
		move->rr--;
	}
	while (move->ra > 0)
	{
		do_rotate(stack, MOVE_RA);
		move->ra--;
	}
	while (move->rb > 0)
	{
		do_rotate(stack, MOVE_RB);
		move->rb--;
	}
}

void	exec_moves_reverse(t_stack *stack, t_move *move)
{
	while (move->rrr > 0)
	{
		do_reverse_rotate(stack, MOVE_RRR);
		move->rrr--;
	}
	while (move->rra > 0)
	{
		do_reverse_rotate(stack, MOVE_RRA);
		move->rra--;
	}
	while (move->rrb > 0)
	{
		do_reverse_rotate(stack, MOVE_RRB);
		move->rrb--;
	}
}

void	exec_moves(t_stack *stack, t_move *move)
{
	exec_moves_rotate(stack, move);
	exec_moves_reverse(stack, move);
	if (move->pa == 1)
	{
		do_push(stack, MOVE_PA);
		move->pa = 0;
	}
}
