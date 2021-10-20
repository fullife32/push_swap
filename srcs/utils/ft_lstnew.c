/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:39:19 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/20 10:28:01 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_lstnew(void)
{
	t_elem	*new;

	/// init value like new = (t_elem){values...}
	new = malloc(sizeof(t_elem));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	return (new);
}
