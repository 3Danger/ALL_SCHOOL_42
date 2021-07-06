#include "printf_header.h"

t_el	check_signs_space_zero(t_el el, char **s)
{
	while (ft_strchr("+- 0", **s))
	{
		if (**s == ' ')
			el.is_space = 1;
		else if (**s == '-')
		{
			el.is_zero = 0;
			el.is_minus = 1;
		}
		else if (**s == '+')
			el.is_plus = 1;
		else if (**s == '0')
			el.is_zero = 1;
		(*s)++;
	}
	return (el);
}

t_el	check_widths(t_el el, va_list args, char **s)
{
	int	i;
	int	tmp;

	i = 0;
	if (**s >= '0' && **s <= '9')
	{
		el.is_width = 1;
		el.width = ft_atoi(*s);
		tmp = el.width;
		while (tmp > 0 && ++i)
			tmp /= 10;
		(*s) += i;
	}
	else if (**s == '*')
	{
		el.is_width = 1;
		el.width = va_arg(args, int);
		if (el.width < 0)
		{
			el.is_minus = 1;
			el.width = -el.width;
		}
		(*s)++;
	}
	return (el);
}

t_el	check_precission_dots(t_el el, va_list args, char **s)
{
	int	i;
	int	tmp;

	i = 0;
	if (**s == '.')
		el.is_dot = 1;
	else
		return (el);
	if ((*(++(*s))) >= '0' && **s <= '9')
	{
		el.is_precission = 1;
		el.precission = ft_atoi(*s);
		tmp = el.precission;
		while (tmp > 0 && ++i)
			tmp /= 10;
		(*s) += i;
	}
	else if (**s == '*')
	{
		el.precission = va_arg(args, int);
		el.is_precission = 1;
		(*s)++;
	}
	return (el);
}

t_el	parse_check_for_flag(t_el el, va_list args, const char *str)
{
	char	*s;

	el = el_set_defaults();
	if (*str == '%')
		el.width_in_format++;
	s = (char *)(str + el.width_in_format);
	while (ft_strchr(ALLOW, *s) && *s)
		s++;
	if (ft_strchr(TYPE, *s) && *s)
		el.type = *s;
	else
		return (el);
	el.width_in_format += s - str;
	s = (char *)str + 1;
	el = check_signs_space_zero(el, &s);
	el = check_widths(el, args, &s);
	el = check_precission_dots(el, args, &s);
	return (el);
}
