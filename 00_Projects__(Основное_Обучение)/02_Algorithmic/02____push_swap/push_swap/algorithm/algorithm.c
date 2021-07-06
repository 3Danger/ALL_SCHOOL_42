#include "alg_utils_proto.h"

void	algorithm(t_stack **a, char **ops)
{
	t_stack	*b;
	short	check;

	b = NULL;
	check = check_sort(*a);
	if (check)
	{
		if (check == 2)
			come(a, lmax_min(*a, DOWN, 0), ops);
		return ;
	}
	if (llen(*a, 0) < 6)
		algorithm_smallsort(a, &b, ops);
	else
		algorithm_bigsort(a, &b, ops);
}
