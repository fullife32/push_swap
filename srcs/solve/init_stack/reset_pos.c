/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:30:19 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 14:30:34 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_pos(t_pos *pos)
{
	pos->a = 0;
	pos->b = 0;
	pos->old_a = -1;
	pos->old_b = -1;
	pos->dist_a = 0;
	pos->dist_b = 0;
	pos->old_dist_a = 0;
	pos->old_dist_b = 0;
	pos->up_a = 0;
	pos->up_b = 0;
	pos->old_up_a = 0;
	pos->old_up_a = 0;
}
