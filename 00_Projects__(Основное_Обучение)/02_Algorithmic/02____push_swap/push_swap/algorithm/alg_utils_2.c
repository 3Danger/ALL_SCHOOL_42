#include "alg_utils_proto.h"

void	magic_algorithm(t_stack **a, t_stack **b, char **ops)
{
	int			divm;
	static int	set_divm;
	t_stack		*tmid;
	int			mid;

	divm = -1;
	set_divm++;
	if (!*a)
		return ;
	divm = ldiv_max_el(*a)->div;
	mid = lget_mid(*a, divm)->var;
	while (1)
	{
		if (!*a)
			break ;
		if ((*a)->stack == A)
			tmid = lnext_ud_mid(*a, mid, DOWN, divm);
		else
			tmid = lnext_ud_mid(*a, mid, UP, divm);
		if (!tmid)
			break ;
		come(a, tmid, ops);
		(*a)->div = set_divm;
		pp(a, b, ops);
	}
}

short	to_short_very_smallsort(t_stack **a, char **ops, int len)
{
	if (!a || !*a || !ops || len == 1)
		return (1);
	if (len == 2)
	{
		if ((*a)->var > (*a)->nxt->var)
			ss(a, ops);
		return (1);
	}
	return (0);
}

void	alg_very_smallsort(t_stack **a, char **ops, int len)
{
	int	imax;
	int	imin;

	if (to_short_very_smallsort(a, ops, len))
		return ;
	imax = lindex(lmax_min(*a, UP, 0));
	imin = lindex(lmax_min(*a, DOWN, 0));
	if (imax == 2)
		if (imin == 1)
			ss(a, ops);
	if (imax == 1)
		if (imin == 2)
			rr(a, DOWN, ops);
	if (imax == 1 && imin == 0)
	{
		rr(a, DOWN, ops);
		ss(a, ops);
	}
	else if (imax == 0)
	{
		rr(a, UP, ops);
		if (imin == 2)
			ss(a, ops);
	}
}

void	algorithm_smallsort(t_stack **a, t_stack **b, char **ops)
{
	int	len;

	len = llen(*a, 0);
	if (len < 4)
	{
		alg_very_smallsort(a, ops, len);
		return ;
	}
	come(a, lmax_min(*a, DOWN, 0), ops);
	pp(a, b, ops);
	come(a, lmax_min(*a, DOWN, 0), ops);
	pp(a, b, ops);
	alg_very_smallsort(a, ops, 3);
	pp(b, a, ops);
	pp(b, a, ops);
}

void	algorithm_bigsort(t_stack **a, t_stack **b, char **ops)
{
	while (!(llen(*a, -1) == llen(*a, INT_MIN) && !*b))
	{
		ret_state(a, ops);
		if (!*b)
			magic_algorithm(a, b, ops);
		else
		{
			if (llen(*b, (*b)->div) < 25)
			{
				while (*b)
				{
					come(b, lmax_min(*b, UP, (*b)->div), ops);
					(*b)->div = -1;
					pp(b, a, ops);
				}
				set_mark_ifsorted(a);
			}
			magic_algorithm(b, a, ops);
		}
	}
	come(a, lmax_min(*a, DOWN, -1), ops);
}
