/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:43:10 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/22 15:09:20 by eassouli         ###   ########.fr       */
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
	int	tmp_size;
	int	*a;
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

typedef struct s_move // Transformer en enum et define chaque element
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

// Initial Check functions
int		initial_check(char **av, t_tab *tab);
int		check_args(char **av, t_tab *tab);

// First Sort functions
int		first_sort(char **av, t_tab *tab);
int		create_tab(char **av, t_tab *tab);
int		*tab_alloc(int size);
int		*tabdup(int *dest, int *source, int size);
void	insertion_sort(t_tab *tab);
int		double_num(t_tab *tab);

// Solve functions
int		solve(t_tab *tab, t_stack *stack, t_move *move);

//	Init Stack functions
int		init_stack(t_tab *tab, t_stack *stack);
t_elem	*create_stack(t_tab *tab, t_stack *stack);
void	target_stack(t_tab *tab, t_elem *elem);

//	Sort functions
int		stack_is_sorted(t_elem **first, int size);

//	Distance Calculation functions

//	Push To A functions

//	Push To B functions
int		longest_sequence(t_seq *seq, t_tab *tab);

// Moves functions
void	swap(t_elem **first, int size);
void	double_swap(t_stack *stack);
void	push(t_elem **from, t_elem **to);
void	rotate(t_elem **first, int size);
void	double_rotate(t_stack *stack);
void	reverse_rotate(t_elem **first, int size);
void	double_reverse_rotate(t_stack *stack);

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