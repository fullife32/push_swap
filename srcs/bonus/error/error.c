/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:50:57 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/28 19:30:24 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	error(t_tab *tab, t_stack *stack, t_inst *inst)
{
	free_push_swap(tab, stack, inst);
	write(1, ERROR, 6);
	return (-1);
}
