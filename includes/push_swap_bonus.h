/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:46:57 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/28 21:44:06 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

/*
** Includes **
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

/*
** Defines **
*/

# define OK "OK\n"
# define KO "KO\n"
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

typedef struct s_tab
{
	int		size;
	int		*sort;
	int		*unsort;
}				t_tab;

typedef struct s_elem
{
	int				target;
	struct s_elem	*next;
}				t_elem;

typedef struct s_stack
{
	int				size_a;
	int				size_b;
	struct s_elem	*a;
	struct s_elem	*b;
	struct s_elem	*first_a;
	struct s_elem	*first_b;
}				t_stack;

typedef struct s_inst
{
	int		move;
	char	*line;
}				t_inst;

/*
** Prototypes **
*/

// Check functions
int		check_args(char **av, t_tab *tab);
int		double_num(t_tab *tab);
int		is_stack_sorted(t_elem *first, int size);

// First Sort functions
int		first_sort(char **av, t_tab *tab);
int		create_tab(char **av, t_tab *tab);
int		*tab_alloc(int size);
int		*tabdup(int *dest, int *source, int size);
void	insertion_sort(t_tab *tab);

// Init Stack functions
int		init_stack(t_tab *tab, t_stack *stack);
t_elem	*create_stack(t_tab *tab, t_stack *stack);
void	target_stack(t_tab *tab, t_elem *elem);

// Instruction loop functions
int		inst_loop(t_stack *stack, t_inst *inst);

// Moves functions
void	swap(t_elem **first, int size);
void	do_swap(t_stack *stack, int move);
void	do_push(t_stack *stack, int move);
void	do_rotate(t_stack *stack, int move);
void	do_reverse_rotate(t_stack *stack, int move);
void	exec_moves(t_stack *stack, int move);

// Free fuctions
int		free_push_swap(t_tab *tab, t_stack *stack, t_inst *inst);
void	free_inst(char **line);

// Error functions
int		error(t_tab *tab, t_stack *stack, t_inst *inst);

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