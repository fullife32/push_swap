/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tabs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:35:44 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/19 14:17:37 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup_tab(t_tab *tab)
{
	tab->tmp_tab = malloc(sizeof(int) * tab->size);
	if (tab->tmp_tab == NULL)
		return (-1);
	ft_memcpy(tab->tmp_tab, tab->sort_tab, tab->size * sizeof(int));
	return (0);
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
			tab->sort_tab[n] = tmp;
			j = next_number(j, av[i]);
			n++;
		}
		i++;
	}
	return (0);
}

int	create_tab(char **av, t_tab *tab)
{
	tab->sort_tab = malloc(sizeof(int) * tab->size);
	if (tab->sort_tab == NULL)
		return (-1);
	if (set_numbers(av, tab) == -1)
		return (-1);
	if (dup_tab(tab) == -1)
		return (-1);
	return (0);
}
