/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:12:46 by eassouli          #+#    #+#             */
/*   Updated: 2021/10/26 18:37:27 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *stack)
{
	printf("----- Stack A ----- %d\n", stack->size_a);
	if (stack->first_a)
	{
		for (t_elem *tmp = stack->first_a; tmp; tmp = tmp->next)
			printf("%p : new pos -> %d\n", tmp, tmp->target);
	}
	else
		printf("Empty\n");
	printf("\n----- Stack B ----- %d\n", stack->size_b);
	if (stack->first_b)
	{
		for (t_elem *tmp = stack->first_b; tmp; tmp = tmp->next)
			printf("%p : new pos -> %d\n", tmp, tmp->target);
	}
	else
		printf("Empty\n");
}

// Test pour push suite la plus longue vers b :
// Si plus proche du debut push avec ra, si plus proche de la fin push avec rra et reverifier liste la plus longue et tout push
// Recuperer position acutuelle avec i (deja fait) et autre position a la fin qui sera decrementée pour rra (decrementer a chaque tour ?)
// Checker a chaque fois si le prochain element a push est plus proche du i ou de la fin
// Permet d'eviter de parcourir toute la liste inutilement

// Idee pour optimiser recuperation liste la plus longue
// Trouver la deuxieme liste la plus longue avant ou apres celle deja recuperee
// Probleme : Savoir si la liste se trouve avant ou apres
// Entrer la deuxieme liste la plus longue avant ou apres celle deja recuperee pour optimiser encore et push moins d'elements
// Exemple 100 200 300 400 500 1 2 3 4 5 6 7 8 9
// Pour l'instant seulement la liste de 1 a 9 est gardee alors que celle de 100 a 500 pourrait aussi l'etre

int	solve(t_tab *tab, t_stack *stack, t_pos *pos, t_move *move)
{
	if (init_stack(tab, stack) == -1)
		return (-1);
	if (push_to_b(&tab->seq, tab, stack) == -1)
		return (-1);
	push_to_a(stack, pos, move);
	// printf("\nsequence : \n");
	// for (int i = 0; i < tab->seq.size; i++)
	// 	printf("%d\n", tab->seq.lis[i]);
	// printf("sequence size = %d\n", tab->seq.size);
	// print_stacks(stack);

	// dist_to_a(stack->first_a, stack->first_b, stack->size_a, stack->size_b);
	// tab->seq.size = tab->size;
	// tabdup(tab->seq.a, tab->unsort, tab->size);
	// for (int i = 0; i < tab->seq.size; i++)
	// 	printf("%d ", tab->seq.a[i]);
	// printf("\n");
	return (0);
}
