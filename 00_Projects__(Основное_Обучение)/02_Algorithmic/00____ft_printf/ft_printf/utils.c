#include "printf_header.h"

int	max_min(int a, int b, int c)
{
	if (c > 0)
	{
		if (a > b)
			return (a);
		return (b);
	}
	else
	{
		if (a > b)
			return (b);
		return (a);
	}
}

int	is_minus(const char *str, t_el el)
{
	int		i;

	i = 0;
	if ((el.precission + 1) > (int)ft_strlen(el.res) && ft_strchr(str, '-'))
		return (1);
	else
		return (0);
}

void	minus_move(char	*str)
{
	int		i;

	i = 0;
	if (!ft_strchr(str, '-'))
		return ;
	while (!ft_isdigit(str[i]))
		i++;
	if (str[i] == '0')
	{
		*ft_strchr(str, '-') = '0';
		*ft_strchr(str, '0') = '-';
	}
}
