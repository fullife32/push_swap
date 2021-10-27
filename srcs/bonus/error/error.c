/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:50:57 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 23:08:12 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	error(t_tab *tab, t_stack *stack)
{
	free_push_swap(tab, stack);
	write(1, ERROR, 6);
	return (-1);
}
