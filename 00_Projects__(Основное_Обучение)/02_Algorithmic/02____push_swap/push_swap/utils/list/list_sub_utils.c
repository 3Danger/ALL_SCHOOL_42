#include "list.h"

t_stack	*lnext_ud_mid(t_stack *start, int mid, int updown, int div)
{
	t_stack	*end;

	if (!start)
		return (NULL);
	lgo_back(&start);
	end = start;
	while (end->nxt)
		end = end->nxt;
	while ((start && end) && (!start->bck
			|| start->bck != end->nxt || !end->nxt
			|| start->bck != end->nxt))
	{
		if (updown == UP && start->var >= mid && start->div == div)
			return (start);
		if (updown == UP && end->var >= mid && end->div == div)
			return (end);
		if (updown == DOWN && start->var <= mid && start->div == div)
			return (start);
		if (updown == DOWN && end->var <= mid && end->div == div)
			return (end);
		start = start->nxt;
		end = end->bck;
	}
	return (NULL);
}

t_stack	*lget_mid(t_stack *lst, int div)
{
	int	lend;

	if (!lst)
		return (NULL);
	lend = llen(lst, div) / 2;
	lst = lmax_min(lst, DOWN, div);
	while (lend--)
		lst = lnext(lst, UP, div);
	return (lst);
}

t_stack	*ldiv_max_el(t_stack *lst)
{
	t_stack	*div_max;

	if (!lst)
		return (NULL);
	div_max = lst;
	while (lst)
	{
		if (div_max->div < lst->div)
			div_max = lst;
		lst = lst->nxt;
	}
	return (div_max);
}

t_stack	*ldiv_max_el_glob(t_stack *lst)
{
	t_stack	*div_max;

	if (!lst)
		return (NULL);
	while (lst->bck_ordr)
		lst =lst->bck_ordr;
	div_max = lst;
	while (lst)
	{
		if (div_max->div < lst->div)
			div_max = lst;
		lst = lst->nxt_ordr;
	}
	return (div_max);
}
