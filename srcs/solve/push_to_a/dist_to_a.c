/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:36:16 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/27 15:00:09 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dist_double_rotate(int fastest, t_pos *pos)
{
	if (pos->a >= pos->b)
	{
		fastest = pos->a;
		pos->dist_a = pos->a;
		pos->dist_b = 0;
		pos->up_a = 1;
		pos->up_b = 1;
	}
	else if (pos->b > pos->a)
	{
		fastest = pos->b;
		pos->dist_b = pos->b;
		pos->dist_a = 0;
		pos->up_a = 1;
		pos->up_b = 1;
	}
	return (fastest);
}

int	dist_double_reverse(int size_a, int size_b, int fastest, t_pos *pos)
{
	if (size_a - pos->a >= size_b - pos->b && size_a - pos->a < fastest)
	{
		fastest = size_a - pos->a;
		pos->dist_a = size_a - pos->a;
		pos->dist_b = 0;
		pos->up_a = 0;
		pos->up_b = 0;
	}
	else if (size_b - pos->b > size_a - pos->a && size_b - pos->b < fastest)
	{
		fastest = size_b - pos->b;
		pos->dist_b = size_b - pos->b;
		pos->dist_a = 0;
		pos->up_a = 0;
		pos->up_b = 0;
	}
	return (fastest);
}

int	dist_simple_rotate(int size_a, int size_b, int fastest, t_pos *pos)
{
	if (size_a - pos->a + pos->b < fastest)
	{
		fastest = size_a - pos->a + pos->b;
		pos->dist_a = size_a - pos->a;
		pos->dist_b = pos->b;
		pos->up_a = 0;
		pos->up_b = 1;
	}
	if (size_b - pos->b + pos->a < fastest)
	{
		fastest = size_b - pos->b + pos->a;
		pos->dist_a = pos->a;
		pos->dist_b = size_b - pos->b;
		pos->up_a = 1;
		pos->up_b = 0;
	}
	return (fastest);
}

void	dist_to_a(int size_a, int size_b, t_pos *pos)
{
	int	fastest;

	fastest = -1;
	fastest = dist_double_rotate(fastest, pos);
	fastest = dist_double_reverse(size_a, size_b, fastest, pos);
	fastest = dist_simple_rotate(size_a, size_b, fastest, pos);
}
