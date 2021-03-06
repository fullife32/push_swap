/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:31:57 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/29 17:00:12 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	inst_loop(t_stack *stack, t_inst *inst)
{
	while (get_next_line(0, &inst->line) == 1)
	{
		if (check_inst(inst) == -1)
			return (-1);
		exec_moves(stack, inst->move);
		free_inst(&inst->line);
	}
	return (0);
}
