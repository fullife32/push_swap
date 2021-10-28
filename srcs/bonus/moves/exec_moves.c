/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:17:42 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/28 20:32:26 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	exec_moves(t_stack *stack, int move)
{
	if (move == MOVE_PA)
		do_push(stack, MOVE_PA);
	if (move == MOVE_PB)
		do_push(stack, MOVE_PB);
	if (move == MOVE_SA)
		do_swap(stack, MOVE_SA);
	if (move == MOVE_SB)
		do_swap(stack, MOVE_SB);
	if (move == MOVE_SS)
		do_swap(stack, MOVE_SS);
	if (move == MOVE_RR)
		do_rotate(stack, MOVE_RR);
	if (move == MOVE_RA)
		do_rotate(stack, MOVE_RA);
	if (move == MOVE_RB)
		do_rotate(stack, MOVE_RB);
	if (move == MOVE_RRR)
		do_reverse_rotate(stack, MOVE_RRR);
	if (move == MOVE_RRA)
		do_reverse_rotate(stack, MOVE_RRA);
	if (move == MOVE_RRB)
		do_reverse_rotate(stack, MOVE_RRB);
}
