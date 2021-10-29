/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:59:53 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/29 17:00:14 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_swap(char *line)
{
	int	i;
	int	move;

	i = 1;
	move = -1;
	if (line[i] == 'a')
		move = MOVE_SA;
	else if (line[i] == 'b')
		move = MOVE_SB;
	else if (line[i] == 's')
		move = MOVE_SS;
	else
		return (-1);
	i++;
	if (line[i] != '\0')
		return (-1);
	return (move);
}

int	check_push(char *line)
{
	int	i;
	int	move;

	i = 1;
	move = -1;
	if (line[i] == 'a')
		move = MOVE_PA;
	else if (line[i] == 'b')
		move = MOVE_PB;
	else if (line[i] == '\0')
		return (-1);
	i++;
	if (line[i] != '\0')
		return (-1);
	return (move);
}

int	check_rotate_case(char *line)
{
	int	i;
	int	move;

	i = 2;
	move = -1;
	if (line[i] == '\0')
		return (MOVE_RR);
	else if (line[i] == 'a')
		move = MOVE_RRA;
	else if (line[i] == 'b')
		move = MOVE_RRB;
	else if (line[i] == 'r')
		move = MOVE_RRR;
	else
		return (-1);
	i++;
	if (line[i] != '\0')
		return (-1);
	return (move);
}

int	check_rotate(char *line)
{
	int	i;
	int	move;

	i = 1;
	move = -1;
	if (line[i] == 'a')
		move = MOVE_RA;
	else if (line[i] == 'b')
		move = MOVE_RB;
	else if (line[i] == 'r')
		return (check_rotate_case(line));
	else
		return (-1);
	i++;
	if (line[i] != '\0')
		return (-1);
	return (move);
}

int	check_inst(t_inst *inst)
{
	if (inst->line[0] == 's')
	{
		inst->move = check_swap(inst->line);
		return (inst->move);
	}
	else if (inst->line[0] == 'p')
	{
		inst->move = check_push(inst->line);
		return (inst->move);
	}
	else if (inst->line[0] == 'r')
	{
		inst->move = check_rotate(inst->line);
		return (inst->move);
	}
	else
		return (-1);
}
