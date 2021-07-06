#include "printf_header.h"

t_el	percent_fill(t_el el)
{
	char	*res;

	if (el.is_width)
	{
		res = (char *)malloc(sizeof(char) * el.width);
		if (el.is_zero && !el.is_minus)
			ft_memset(res, '0', el.width);
		else
			ft_memset(res, ' ', el.width);
		if (el.is_minus)
			res[0] = '%';
		else
			res[el.width - 1] = '%';
	}
	else
	{
		res = (char *)malloc(sizeof(char));
		*res = '%';
		el.width = 1;
	}
	free(el.res);
	el.res = res;
	return (el);
}

char	*filler(char c, int size)
{
	char	*fill;

	fill = (char *)malloc(sizeof(char) * (size + 1));
	ft_memset(fill, c, size);
	fill[size] = 0;
	return (fill);
}

t_el	pointer_fill(t_el el)
{
	int		len;
	int		len2;
	int		precission;
	int		width;
	char	*res;

	if (*el.res == '0' && el.is_dot && el.precission == 0)
		*el.res = 0;
	len = ft_strlen(el.res);
	precission = max_min(el.precission, len, 1);
	width = max_min(el.width, precission, 1);
	res = concat_fr2("0x", filler('0', max_min(el.precission - len, 0, 1)));
	res = concatenate(res, ft_strdup(el.res));
	len2 = ft_strlen(res);
	width = max_min(width - len2, 0, 1);
	if (el.is_minus)
		res = concatenate(res, filler(' ', width));
	else
		res = concatenate(filler(' ', width), res);
	free(el.res);
	el.res = res;
	el.width = ft_strlen(res);
	return (el);
}

t_el	res_calculation(t_el el)
{
	if (el.type == '%')
		el = percent_fill(el);
	if (el.type == 'c' || el.type == 's')
		el = string_fill(el);
	if (el.type == 'd' || el.type == 'i' || el.type == 'u'
		|| el.type == 'x' || el.type == 'X')
		el = digit_fill(el);
	if (el.type == 'p')
		el = pointer_fill(el);
	return (el);
}
