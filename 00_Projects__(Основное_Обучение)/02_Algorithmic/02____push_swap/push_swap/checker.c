#include "push_swap.h"
#include "gnl/get_next_line.h"
#include <string.h>

short	is_equal(char *a, char *b)
{
	int	lena;
	int	lenb;

	lena = ft_strlen(a);
	lenb = ft_strlen(b);
	if (lena != lenb)
		return (0);
	while (lena-- > 0)
		if (a[lena] != b[lena])
			return (0);
	return (1);
}

short	to_do_list_ops(t_stack **a, t_stack **b, char *sops)
{
	short	check;

	check = 0;
	if (is_equal(sops, "sa") || is_equal(sops, "ss"))
		check = ss(a, NULL);
	if (is_equal(sops, "sb") || is_equal(sops, "ss"))
		check = ss(b, NULL);
	else if (is_equal(sops, "pa"))
		check = pp(b, a, NULL);
	else if (is_equal(sops, "pb"))
		check = pp(a, b, NULL);
	if (is_equal(sops, "ra") || is_equal(sops, "rr"))
		check = rr(a, UP, NULL);
	if (is_equal(sops, "rb") || is_equal(sops, "rr"))
		check = rr(b, UP, NULL);
	if (is_equal(sops, "rra") || is_equal(sops, "rrr"))
		check = rr(a, DOWN, NULL);
	if (is_equal(sops, "rrb") || is_equal(sops, "rrr"))
		check = rr(b, DOWN, NULL);
	return (check);
}

void	check_list(t_stack *sta)
{
	lgo_back(&sta);
	if (!sta)
	{
		write(1, "KO\n", 3);
		return ;
	}
	while (sta)
	{
		if (sta->nxt != sta->nxt_ordr)
		{
			write(1, "KO\n", 3);
			return ;
		}
		sta = sta->nxt;
	}
	write (1, "OK\n", 3);
}

int	main(int argc, char const *argv[])
{
	int		*input;
	t_stack	*sta;
	t_stack	*stb;
	char	*op;

	argc--;
	op = NULL;
	if (argc == 0)
	{
		write(1, "Введите числа.\n", 28);
		exit(EXIT_FAILURE);
	}
	input = handler_input(&argv[1], &argc);
	l_iarr_convert(&sta, input, argc);
	while (get_next_line(1, &op) > 0)
	{
		if (!to_do_list_ops(&sta, &stb, op))
			break ;
		free(op);
	}
	check_list(sta);
	free(input);
	lfree_full(&sta);
}
