#include "printf_header.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_el	el;
	int		len[2];
	char	*res;
	int		i;

	i = (len[0] = (len[1] = 0));
	res = ft_strdup("");
	va_start(args, format);
	while (format && format[i])
	{
		while (format[i + len[1]] && format[i + len[1]] != '%')
			len[1]++;
		res = concatenate_fr1(res, len[0], &((char *)format)[i], len[1]);
		el = parse_check_for_flag(el, args, &format[i + len[1]]);
		el = el_to_res(el, args);
		el = res_calculation(el);
		res = concatenate_frbth(res, len[0] + len[1], el.res, el.width);
		i += el.width_in_format + len[1];
		len[0] += el.width + len[1] + (len[1] = 0);
	}
	write (1, res, len[0]);
	va_end(args);
	free(res);
	return (len[0]);
}
