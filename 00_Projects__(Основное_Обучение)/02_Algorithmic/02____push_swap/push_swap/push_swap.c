#include "push_swap.h"
#include "libft/libft.h"

int	lentab(char **ops)
{
	int	i;

	i = 0;
	while (ops[i])
		i++;
	return (i);
}

int	main(int argc, char const *argv[])
{
	int		*input;
	t_stack	*sta;
	char	**ops;

	argc--;
	if (argc == 0)
	{
		write(1, "Введите числа.\n", 28);
		exit(EXIT_FAILURE);
	}
	input = handler_input(&argv[1], &argc);
	l_iarr_convert(&sta, input, argc);
	ops = (char **)malloc(sizeof(char *) * (argc * 120));
	if (!ops)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	ft_bzero(ops, sizeof(char *) * (argc * 120));
	algorithm(&sta, ops);
	ops_print(ops);
	free(input);
	lfree_full(&sta);
	ops_free(ops);
}
