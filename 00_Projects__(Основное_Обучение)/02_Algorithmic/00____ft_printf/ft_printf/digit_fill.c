#include "printf_header.h"

void	memmer(char **res, t_el el, int len)
{
	ft_memset(*res, ' ', el.width);
	if (el.is_zero && !el.is_precission)
		el.precission = el.width;
	if (el.is_minus)
	{
		ft_memset(*res, '0', el.precission);
		ft_memcpy(&res[0][el.precission - len], el.res, len);
	}
	else
	{
		ft_memset(&res[0][el.width - el.precission], '0', el.precission);
		ft_memcpy(&res[0][el.width - len], el.res, len);
	}
}

void	el_process(t_el *el, int len)
{
	if (el->is_minus)
		el->is_zero = 0;
	if (el->is_width && el->width == 0 && el->precission < 0)
		el->precission = len;
	if (el->is_zero && el->is_width && el->precission < 0 && el->is_precission)
		el->precission = el->width;
}

t_el	digit_fill(t_el el)
{
	int		len;
	char	*res;
	int		is_min_lc;

	is_min_lc = is_minus(el.res, el);
	len = ft_strlen(el.res);
	el_process(&el, len);
	if (el.is_dot && el.precission == 0 && *el.res == '0')
	{
		free(el.res);
		el.res = ft_strdup("");
		len = 0;
	}
	else
	{
		el.precission = max_min(el.precission, len, 1) + is_min_lc;
		el.width = max_min(el.width, el.precission, 1);
	}
	res = (char *)malloc(sizeof(char) * el.width);
	memmer(&res, el, len);
	free(el.res);
	minus_move(res);
	el.res = res;
	return (el);
}
