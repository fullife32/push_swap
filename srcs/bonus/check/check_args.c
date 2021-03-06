/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:53:08 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 23:08:05 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_only_num(char *number)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (number[i])
	{
		while (number[i] == ' ')
			i++;
		if (number[i] == '-' || number[i] == '+')
			i++;
		if (number[i] < '0' || number[i] > '9')
			return (0);
		while (number[i] >= '0' && number[i] <= '9')
			i++;
		count++;
		if (number[i] != ' ' && number[i] != '\0')
			return (0);
		while (number[i] == ' ')
			i++;
	}
	return (count);
}

int	check_args(char **av, t_tab *tab)
{
	int	i;
	int	count;

	i = 1;
	while (av[i])
	{
		count = is_only_num(av[i]);
		if (count == 0)
			return (-1);
		tab->size += count;
		i++;
	}
	return (0);
}
