#include "../../libft/libft.h"

int		ft_split_len(char	**tabs);
void	free_split(char **tabs);
short	validate(char **input, int size);

short	is_not_dup(int *res, int size)
{
	int	i;
	int	j;

	if (!res)
		return (0);
	if (size < 0)
		size = -size;
	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (res[i] == res[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

short	check_intmax(char *str)
{
	size_t	len;
	long	check;
	short	i;

	i = 0;
	check = 0;
	len = ft_strlen(str);
	if (len == 10)
	{
		while (str[i])
			check = check * 10 + str[i++] - 48;
		if (check > 2147483647)
			return (1);
	}
	else if (len > 10)
		return (1);
	return (0);
}

int	*ft_atoi_arr(char **str, int size)
{
	int	*res;
	int	i;

	if (!str || !*str)
		return (NULL);
	if (size < 0)
		size = -size;
	res = (int *)malloc(sizeof(int) * size);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		if (check_intmax(str[i]))
		{
			free(res);
			return (NULL);
		}
		res[i] = ft_atoi(str[i]);
	}
	return (res);
}

void	check_one_line(int *size, char ***input, const char **argv)
{
	if (*size == 1)
	{
		*input = ft_split(*argv, ' ');
		if (!*input)
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		*size = -ft_split_len(*input);
	}
	else
		*input = (char **)argv;
}

int	*handler_input(const char **argv, int *size)
{
	char	**input;
	int		*res;
	int		i;

	input = NULL;
	res = NULL;
	check_one_line(size, &input, argv);
	res = ft_atoi_arr(input, *size);
	if (!validate(input, *size) || !is_not_dup(res, *size))
	{
		if (*size < 0 && input)
			free_split(input);
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (*size < 0)
	{
		i = 0;
		while (input[i])
			free(input[i++]);
		free(input);
		*size *= -1;
	}
	return (res);
}
