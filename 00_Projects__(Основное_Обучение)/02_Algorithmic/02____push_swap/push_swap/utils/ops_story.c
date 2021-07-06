#include "../push_swap.h"
static void	ops_add_to_short(char **ops, short operarion, short stack, int *i)
{
	if (operarion == R && ops)
	{
		if (stack == A)
			ops[(*i)++] = ft_strdup("ra\n");
		else if (stack == B)
			ops[(*i)++] = ft_strdup("rb\n");
		else if (stack == AB)
			ops[(*i)++] = ft_strdup("rr\n");
	}
	else if (operarion == RR && ops)
	{
		if (stack == A)
			ops[(*i)++] = ft_strdup("rra\n");
		else if (stack == B)
			ops[(*i)++] = ft_strdup("rrb\n");
		else if (stack == AB)
			ops[(*i)++] = ft_strdup("rrr\n");
	}
}

int	ops_add(char **ops, short operarion, short stack)
{
	static int	i;

	if (operarion == P && ops)
	{
		if (stack == A)
			ops[i++] = ft_strdup("pa\n");
		else if (stack == B)
			ops[i++] = ft_strdup("pb\n");
	}
	else if (operarion == S && ops)
	{
		if (stack == A)
			ops[i++] = ft_strdup("sa\n");
		else if (stack == B)
			ops[i++] = ft_strdup("sb\n");
		else if (stack == AB)
			ops[i++] = ft_strdup("ss\n");
	}
	ops_add_to_short(ops, operarion, stack, &i);
	return (i);
}

void	ops_print(char **ops)
{
	while (*ops)
		ft_putstr_fd(*ops++, 1);
}

void	ops_free(char **ops)
{
	int	size;

	if (!ops)
		exit(EXIT_FAILURE);
	size = ops_add(NULL, INT16_MIN, INT16_MIN);
	while (size-- > 0)
		free(ops[size]);
	free(ops);
}
