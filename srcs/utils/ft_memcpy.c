/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:44:15 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/19 13:47:42 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	if (!dst && !src && n > 0)
		return (NULL);
	dest = dst;
	source = (unsigned char *)src;
	i = 0;
	while (n-- != 0)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
