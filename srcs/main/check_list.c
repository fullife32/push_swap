/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:53:08 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/18 18:11:45 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_allowed_char(char n)
{
	if (n >= '0' && n <= '9')
		return (1);
	if (n == '-')
		return (1);
	return (0);
}

int	is_only_num(char *number)
{
	int	i;
	
	i = 0;
	while (number[i])
	{
		if (is_allowed_char(number[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_list(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (is_only_num(av[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}
