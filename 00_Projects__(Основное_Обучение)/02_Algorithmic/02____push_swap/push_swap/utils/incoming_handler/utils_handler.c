#include <stdlib.h>

int	ft_split_len(char	**tabs)
{
	int	i;

	i = 0;
	if (!tabs || !*tabs)
		return (0);
	while (tabs[i])
		i++;
	return (i);
}

void	free_split(char **tabs)
{
	int	i;

	i = 0;
	while (tabs[i])
	{
		free(tabs[i]);
		i++;
	}
	free(tabs);
}

short	validate(char **input, int size)
{
	int	i;
	int	j;

	if (!input || !*input)
		return (-1);
	i = 0;
	j = 0;
	if (size < 0)
		size = -size;
	while (i < size)
	{
		while (input[i][j])
		{
			if (!((input[i][j] >= '0' && input[i][j] <= '9')
				|| (input[i][j] == '-') || (input[i][j] == '+')))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
