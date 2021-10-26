/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_loop_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:01:17 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/26 19:57:56 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_pos(t_pos *pos)
{
	pos->a = 0;
	pos->b = 0;
	pos->old_a = -1;
	pos->old_b = -1;
	pos->dist_a = 0;
	pos->dist_b = 0;
	pos->old_dist_a = 0;
	pos->old_dist_b = 0;
}

void	find_moves(int size_a, int size_b, t_pos *pos, t_move *move)
{
	if (pos->old_a < size_a / 2)
		move->ra = pos->old_a + 1;
	else if (pos->old_a >= size_a / 2)
		move->rra = size_a - pos->old_a;
	if (pos->old_b < size_b / 2)
		move->rb = pos->old_b;
	else if (pos->old_b >= size_b / 2)
		move->rrb = size_b - pos->old_b;
	if (move->ra != 0 && move->rb != 0)
	{
		if (move->ra > move->rb)
			move->rr = move->ra - move->rb;
		else
			move->rr = move->rb - move->ra;
		move->ra -= move->rr;
		move->rb -= move->rr;
	}
	else if (move->rra != 0 && move->rrb != 0)
	{
		if (move->rra > move->rrb)
			move->rrr = move->rra - move->rrb;
		else
			move->rrr = move->rrb - move->rra;
		move->rra -= move->rrr;
		move->rrb -= move->rrr;
	}
	move->pa = 1;
}

void	exec_moves(t_stack *stack, t_move *move)
{
	while (move->rrr > 0)
	{
		do_reverse_rotate(stack, MOVE_RRR);
		move->rrr--;
	}
	while (move->rra > 0)
	{
		do_reverse_rotate(stack, MOVE_RRA);
		move->rra--;
	}
	while (move->rrb > 0)
	{
		do_reverse_rotate(stack, MOVE_RRB);
		move->rrb--;
	}
	while (move->rr > 0)
	{
		do_rotate(stack, MOVE_RR);
		move->rr--;
	}
	while (move->ra > 0)
	{
		do_rotate(stack, MOVE_RA);
		move->ra--;
	}
	while (move->rb > 0)
	{
		do_rotate(stack, MOVE_RB);
		move->rb--;
	}
	if (move->pa == 1)
	{
		do_push(stack, MOVE_PA);
		move->pa = 0;
	}
}

void	find_final_moves(int size_a, t_elem *first_a, t_move *move)
{
	int		i;
	t_elem	*elem;

	i = 0;
	elem = first_a;
	while (elem->target != 0)
	{
		i++;
		elem = elem->next;
	}
	if (i == 0)
		return;
	if (i < size_a / 2)
		move->ra = i;
	else
		move->rra = size_a - i;
}

void	find_pos_a(int target, t_stack *stack, t_pos *pos)
{
	int		i;
	int		near;
	t_elem	*stack_a;

	i = 0;
	near = -1;
	pos->a = 0;
	stack_a = stack->first_a;
	while (stack_a)
	{
		if ((near == -1 || stack_a->target - target < near)
		&& stack_a->target - target > 0)
		{
			near = stack_a->target - target;
			pos->a = i;
		}
		i++;
		stack_a = stack_a->next;
	}
}

void	dist_to_a(int size_a, int size_b, t_pos *pos)
{
	if (pos->a < size_a / 2)
		pos->dist_a = pos->a;
	else if (pos->a >= size_a / 2)
		pos->dist_a = size_a - pos->a;
	if (pos->b < size_b / 2)
		pos->dist_b = pos->b;
	else if (pos->b >= size_b / 2)
		pos->dist_b = size_b - pos->b;
	// printf("%d - %d = %d\n", size_b, pos->b, size_b - pos->b);
}

void	keep_best_pos(int size_a, int size_b, t_pos *pos)
{
	int	number_of_moves;
	int	old_number_of_moves;

	dist_to_a(size_a, size_b, pos);
	number_of_moves = pos->dist_a + pos->dist_b;
	old_number_of_moves = pos->old_dist_a + pos->old_dist_b;
	if (pos->old_a == -1 || number_of_moves < old_number_of_moves)
	{
		pos->old_dist_a = pos->dist_a;
		pos->old_a = pos->a;
		pos->old_dist_b = pos->dist_b;
		pos->old_b = pos->b;
	}
}

void	push_to_a(t_stack *stack, t_pos *pos, t_move *move)
{
	t_elem	*stack_b;
	int i = 0;
	while (is_stack_sorted(stack->first_a, stack->size_b) == 0)
	{
		print_stacks(stack);
		stack_b = stack->first_a;
		while (stack_b)
		{
			find_pos_a(stack_b->target, stack, pos);
			keep_best_pos(stack->size_a, stack->size_b, pos);
			stack_b = stack_b->next;
			pos->b++;
		}
		// printf("a %d b %d old a %d old b %d da %d db %d old da %d old db %d\n", pos->a, pos->b, pos->old_a, pos->old_b, pos->dist_a, pos->dist_b, pos->old_dist_a, pos->old_dist_b);
		reset_moves(move);
		if (stack->first_b == NULL)
			find_final_moves(stack->size_a, stack->first_a, move);
		else
			find_moves(stack->size_a, stack->size_b, pos, move);
		// printf("sa %d sb %d ss %d pa %d pb %d ra %d rb %d rr %d rra %d rrb %d rrr %d\n", move->sa, move->sb, move->ss, move->pa, move->pb, move->ra, move->rb, move->rr, move->rra, move->rrb, move->rrr);
		exec_moves(stack, move);
		reset_pos(pos);
		// if (stack->first_b == NULL)
		// 	return ;
		if (i == 5)
			return ;
		i++;
	}
}
