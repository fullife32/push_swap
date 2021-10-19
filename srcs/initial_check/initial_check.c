/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:26:18 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/19 12:11:56 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initial_check(char **av, t_tab *tab)
{
	if (check_list(av, tab) == -1) /// move to main if no other functions
		return (-1);
	return (0);
}
