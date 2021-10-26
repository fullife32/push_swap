/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:38:16 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/26 15:38:28 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_moves(t_move *move)
{
	move->sa = 0;
	move->sb = 0;
	move->ss = 0;
	move->pa = 0;
	move->pb = 0;
	move->ra = 0;
	move->rb = 0;
	move->rr = 0;
	move->rra = 0;
	move->rrb = 0;
	move->rrr = 0;
}
