/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:43:10 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/29 17:48:11 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** Includes **
*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
** Defines **
*/

# define ERROR "Error\n"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

enum e_move {
	MOVE_SA,
	MOVE_SB,
	MOVE_SS,
	MOVE_PA,
	MOVE_PB,
	MOVE_RA,
	MOVE_RB,
	MOVE_RR,
	MOVE_RRA,
	MOVE_RRB,
	MOVE_RRR
};

/*
** Structures **
*/

typedef struct s_seq
{
	int	size;
	int	shift;
	int	*lis;
	int	*tmp;
}				t_seq;

typedef struct s_tab
{
	int		size;
	int		*sort;
	int		*unsort;
	t_seq	seq;
}				t_tab;

typedef struct s_elem
{
	int				target;
	int				push;
	struct s_elem	*next;
}				t_elem;

typedef struct s_stack
{
	int				dst;
	int				size_a;
	int				size_b;
	struct s_elem	*a;
	struct s_elem	*b;
	struct s_elem	*first_a;
	struct s_elem	*first_b;
}				t_stack;

typedef struct s_pos
{
	int	a;
	int	b;
	int	old_a;
	int	old_b;
	int	dist_a;
	int	dist_b;
	int	old_dist_a;
	int	old_dist_b;
	int	up_a;
	int	up_b;
	int	old_up_a;
	int	old_up_b;
}				t_pos;

/*
		-- Stack moves explanation ---
** sa : Swap first 2 elements of stack a
** sb : Swap first 2 elements of stack b
** ss : sa && sb
** pa : Push from b to a | Nothing if no element in b
** pb : Push from a to b | Nothing if no element in a
** ra : Move up all elements in a (First becomes last)
** rb : Move up all elements in b (First becomes last)
** rr : ra && rb
** rra : Move down all elements in a (Last becomes first)
** rrb : Move down all elements in b (Last becomes first)
** rrr : rra && rrb
*/

typedef struct s_move
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}				t_move;

/*
** Prototypes **
*/

// Check functions
int		check_args(char **av, t_tab *tab);
int		double_num(t_tab *tab);

// First Sort functions
int		first_sort(char **av, t_tab *tab);
int		create_tab(char **av, t_tab *tab);
int		*tab_alloc(int size);
int		*tabdup(int *dest, int *source, int size);
void	insertion_sort(t_tab *tab);

// Solve functions
//	Sort Stack functions
int		solve(t_tab *tab, t_stack *stack, t_pos *pos, t_move *move);
int		is_stack_sorted(t_elem *first, int size);

//	Init Stack functions
int		init_stack(t_tab *tab, t_stack *stack);
t_elem	*create_stack(t_tab *tab, t_stack *stack);
void	target_stack(t_tab *tab, t_elem *elem);
void	reset_pos(t_pos *pos);

// Little Stack functions
void	little_stack(t_stack *stack);
void	push_smallest(t_stack *stack, int smallest);
void	stack_three(t_stack *stack);
void	stack_four(t_stack *stack);
void	stack_five(t_stack *stack);

//	Push To B functions
void	push_to_b(t_seq *seq, t_tab *tab, t_stack *stack);
int		longest_sequence(t_seq *seq, t_tab *tab, int size);
void	shift_tab(t_seq *seq, t_tab *tab);
void	unshift_seq(t_seq *seq, int size);
void	set_push_elem(int size, int lis_size, int *lis, t_elem *elem);
int		next_elem_to_push(t_elem *elem);

//	Push To A functions
void	push_to_a(t_stack *stack, t_pos *pos, t_move *move);
void	find_pos_a(int target, t_stack *stack, t_pos *pos);
void	dist_to_a(int size_a, int size_b, t_pos *pos);
void	keep_best_pos(int size_a, int size_b, t_pos *pos);

// Moves functions
void	reset_moves(t_move *move);
void	swap(t_elem **first, int size);
void	do_swap(t_stack *stack, int move);
void	do_push(t_stack *stack, int move);
void	do_rotate(t_stack *stack, int move);
void	do_reverse_rotate(t_stack *stack, int move);
void	find_moves(int size_a, int size_b, t_pos *pos, t_move *move);
void	find_final_moves(int size_a, t_elem *first_a, t_move *move);
void	exec_moves(t_stack *stack, t_move *move);

// Free fuctions
int		free_push_swap(t_tab *tab, t_stack *stack);

// Error functions
int		error(t_tab *tab, t_stack *stack);

// Utils functions
long	ft_atol(const char *str);
void	ft_lstadd_back(t_elem **alst, t_elem *new);
void	ft_lstadd_front(t_elem **alst, t_elem *new);
void	ft_lstclear(t_elem **lst);
void	ft_lstdelone(t_elem *lst);
t_elem	*ft_lstlast(t_elem *lst);
t_elem	*ft_lstnew(void);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);

#endif