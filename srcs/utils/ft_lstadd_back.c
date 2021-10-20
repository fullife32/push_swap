/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:37:18 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/20 10:17:43 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_elem **alst, t_elem *new)
{
	if (!alst || !new)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
		ft_lstlast(*alst)->next = new;
}
