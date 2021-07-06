#include "printf_header.h"

t_el	el_to_res(t_el el, va_list args)
{
	char	*c;

	if (ft_strchr("id", el.type) && el.type)
		el.res = ft_itoa(va_arg(args, int));
	if (ft_strchr("u", el.type) && el.type)
		el.res = ft_uitoa(va_arg(args, unsigned int));
	if (ft_strchr("xX", el.type) && el.type)
		el.res = ft_hex_gen_int(va_arg(args, int), el.type);
	if (ft_strchr("p", el.type) && el.type)
		el.res = ft_hex_gen_long(va_arg(args, long));
	if (ft_strchr("s", el.type) && el.type)
		el.res = ft_strdup(va_arg(args, char *));
	if (ft_strchr("c%%", el.type) && el.type)
	{
		c = (char *)malloc(sizeof(char));
		if (el.type == 'c')
			*c = va_arg(args, int);
		else
			*c = '%';
		el.res = c;
	}
	return (el);
}
