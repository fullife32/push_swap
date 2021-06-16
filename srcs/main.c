#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)av;
	int *a_stack;
	int *b_stack;

	if (ac < 2)
		return (0);
	a_stack = malloc(sizeof(int) * ac - 1);
	if (a_stack == NULL)
		return (-1);
	b_stack = malloc(sizeof(int) * ac - 1);
	if (b_stack == NULL)
		return (-1);
	printf("%dtest\n", a_stack[0]);
	return (0);
}