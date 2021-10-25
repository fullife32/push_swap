/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tabs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:35:44 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/25 17:41:10 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*tab_alloc(int size)
{
	int	*tab;

	tab = malloc(sizeof(int) * size);
	return (tab);
}

int	*tabdup(int *dest, int *source, int size)
{
	ft_memcpy(dest, source, size * sizeof(int));
	return (dest);
}

int	next_number(int n, char *arg)
{
	while (arg[n] == ' ')
		n++;
	if (arg[n] == '-' || arg[n] == '+')
		n++;
	while (arg[n] >= '0' && arg[n] <= '9')
		n++;
	while (arg[n] == ' ')
		n++;
	return (n);
}

int	set_numbers(char **av, t_tab *tab)
{
	int		i;
	int		j;
	int		n;
	long	tmp;

	i = 1;
	n = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			tmp = atol(av[i] + j);
			if (tmp > INT_MAX || tmp < INT_MIN)
				return (-1);
			tab->unsort[n] = tmp;
			j = next_number(j, av[i]);
			n++;
		}
		i++;
	}
	return (0);
}

int	create_tab(char **av, t_tab *tab)
{
	tab->unsort = tab_alloc(tab->size);
	if (tab->unsort == NULL)
		return (-1);
	if (set_numbers(av, tab) == -1)
		return (-1);
	return (0);
}
