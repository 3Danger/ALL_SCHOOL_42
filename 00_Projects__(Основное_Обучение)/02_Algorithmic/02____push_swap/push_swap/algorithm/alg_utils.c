#include "../push_swap.h"

void	come(t_stack **base, t_stack *el, char **ops)
{
	int	len;
	int	index_el;

	if (!base || !*base || !(*base)->nxt || !el)
		return ;
	lgo_back(base);
	len = llen(*base, INT_MIN);
	index_el = lindex(el);
	if (*base == el)
		return ;
	if (len / 2 >= index_el)
		while (*base != el)
			rr(base, UP, ops);
	else
		while (*base != el)
			rr(base, DOWN, ops);
}

void	ret_state(t_stack **a, char **ops)
{
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	if (llen(*a, -1) == 0 || llen(*a, 0) == 0)
		return ;
	tmp = lmax_min(*a, UP, -1);
	if (tmp && tmp->nxt)
		come(a, tmp->nxt, ops);
}

short	check_sort(t_stack	*lst)
{
	t_stack	*tmp;

	tmp =lst;
	if (lst->nxt == lst->nxt_ordr || !lst->nxt_ordr)
		lst = lst->nxt;
	else if (lst->nxt == lst->nxt_ordr || !lst->nxt)
		lst = lst->nxt_ordr;
	else
		return (0);
	while (lst && (lst->nxt || lst->nxt_ordr))
	{
		if (tmp == lst)
			return (2);
		else if (lst->nxt == lst->nxt_ordr || !lst->nxt_ordr)
			lst = lst->nxt;
		else if (lst->nxt == lst->nxt_ordr || !lst->nxt)
			lst = lst->nxt_ordr;
		else
			return (0);
	}
	return (1);
}

void	to_short_set_mark_ifsorted(t_stack	*min_el)
{
	if (!min_el->nxt && min_el->nxt_ordr
		&& min_el->nxt_ordr->stack == A && !min_el->nxt_ordr->bck)
	{
		min_el = min_el->nxt_ordr;
		min_el->div = -1;
	}
	while (min_el->nxt == min_el->nxt_ordr && min_el->nxt)
	{
		min_el->nxt->div = -1;
		min_el = min_el->nxt;
	}
}

void	set_mark_ifsorted(t_stack **a)
{
	int		len;
	t_stack	*min_el;

	len = llen(*a, -1);
	if (len == 0 || len == llen(*a, INT_MIN))
		return ;
	min_el = lmax_min(*a, DOWN, -1);
	while (min_el->div == -1 && min_el->nxt == min_el->nxt_ordr)
	{
		min_el = min_el->nxt;
		if (min_el->div != -1)
		{
			min_el->div = -1;
			break ;
		}
	}
	if (min_el->nxt != min_el->nxt_ordr && min_el->nxt)
		return ;
	to_short_set_mark_ifsorted(min_el);
}
