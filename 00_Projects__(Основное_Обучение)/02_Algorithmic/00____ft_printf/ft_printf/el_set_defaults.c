#include "printf_header.h"

t_el	el_set_defaults(void)
{
	t_el	el;

	el.res = NULL;
	el.type = 0;
	el.width = 0;
	el.precission = 0;
	el.width_in_format = 0;
	el.is_width = 0;
	el.is_precission = 0;
	el.is_dot = 0;
	el.is_space = 0;
	el.is_minus = 0;
	el.is_plus = 0;
	el.is_zero = 0;
	return (el);
}
