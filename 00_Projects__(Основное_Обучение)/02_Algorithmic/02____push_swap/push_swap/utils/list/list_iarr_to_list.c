#include "list.h"
void	l_iarr_convert(t_stack **out, int *iarr, int size)
{
	t_stack	*el;

	while (size-- > 0)
	{
		el = lnew_el(iarr[size]);
		if (!el)
		{
			lfree(out);
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		ladd_front(out, el);
	}
	linit(*out);
}
