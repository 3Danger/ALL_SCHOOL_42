#include "printf_header.h"

void	mem_process(char **res, t_el el)
{
	*res = (char *)malloc(sizeof(char) * el.width);
	ft_memset(*res, ' ', el.width);
	if (el.is_zero && !el.is_minus)
		ft_memset(*res, '0', el.width);
	if (el.is_minus)
		ft_memcpy(*res, el.res, el.precission);
	else
		ft_memcpy(&res[0][el.width - el.precission], el.res, el.precission);
}

t_el	string_fill(t_el el)
{
	int		len;
	char	*res;

	if (el.res == NULL)
		len = ft_strlen(el.res = ft_strdup("(null)"));
	else
		len = ft_strlen(el.res);
	if (el.type == 'c')
		el.precission = (len = 1);
	if (el.precission < 0)
		el.precission = len;
	if (el.is_precission)
		el.precission = max_min(el.precission, len, 0);
	if (el.width < el.precission)
		el.width = el.precission;
	if (el.is_precission)
		el.precission = max_min(el.precission, len, 0);
	else if (!el.is_dot)
		el.precission = len;
	el.width = max_min(el.width, el.precission, 1);
	mem_process(&res, el);
	free(el.res);
	el.res = res;
	return (el);
}
