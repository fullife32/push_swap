/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:21:38 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 23:10:08 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bytes;

	bytes = b;
	while (len-- != 0)
		bytes[len] = c;
	return (b);
}
