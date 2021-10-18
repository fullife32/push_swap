#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac < 2) /// Return error if no num ?
		return (0);
	if (check_list(av) == -1)
		return (error());
	write(1, "OK\n", 3);
	return (0);
}
