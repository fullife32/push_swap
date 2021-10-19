/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:43:10 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/19 14:24:56 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR "Error\n"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_tab
{
	int	size;
	int	*sort_tab;
	int	*tmp_tab;
}				t_tab;

// Initial check functions
int		initial_check(char **av, t_tab *tab);
int		check_list(char **av, t_tab *tab);

// First sort functions
int		first_sort(char **av, t_tab *tab);
int		create_tab(char **av, t_tab *tab);
void	insertion_sort(t_tab *tab);

// Free fuctions
void	free_push_swap(t_tab *tab);

// Error functions
int		error(t_tab *tab);

// Utils functions
long	ft_atol(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);

#endif