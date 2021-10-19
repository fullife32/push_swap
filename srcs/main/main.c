/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:32:40 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/19 16:20:15 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_tab	tab;

	tab = (t_tab){0, NULL, NULL};
	if (ac < 2) /// Return error if no num ?
		return (0);
	if (initial_check(av, &tab) == -1)
		return (error(&tab));
	if (first_sort(av, &tab) == -1)
		return (error(&tab));
	free_push_swap(&tab);
	return (0);
}
