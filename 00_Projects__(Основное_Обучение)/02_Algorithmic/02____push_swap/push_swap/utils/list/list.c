#include "list.h"
#include "../../push_swap.h"

t_stack	*lnew_el(int val)
{
	t_stack	*el;

	el = (t_stack *)malloc(sizeof(t_stack));
	if (!el)
		return ((t_stack *)0);
	el->var = val;
	el->bck = (t_stack *)0;
	el->nxt = (t_stack *)0;
	el->bck_ordr = (t_stack *)0;
	el->nxt_ordr = (t_stack *)0;
	el->div = 0;
	el->stack = A;
	return (el);
}

short	ladd_front(t_stack **lst, t_stack *el)
{
	if (!el)
		return (-1);
	if (!lst)
		return (-2);
	if (!*lst)
	{
		*lst = el;
		return (0);
	}
	el->nxt = *lst;
	(*lst)->bck = el;
	(*lst) = el;
	return (0);
}

t_stack	*lmax_min(t_stack *lst, short updown, int div)
{
	t_stack	*mm;

	if (!lst)
		return ((void *)0);
	mm = lst;
	while (mm && mm->div != div)
		mm = mm->nxt;
	if (!mm)
		return (NULL);
	while (lst)
	{
		if (updown == DOWN)
			if (mm->var > lst->var && lst->div == div)
				mm = lst;
		if (updown == UP)
			if (mm->var < lst->var && lst->div == div)
				mm = lst;
		lst = lst->nxt;
	}
	return (mm);
}

int	llen(t_stack *lst, int div)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	lgo_back(&lst);
	while (lst)
	{
		if (lst->div == div || div == INT_MIN)
			i++;
		lst = lst->nxt;
	}
	return (i);
}

int	lindex(t_stack *lst)
{
	int	i;

	if (!lst)
		return (-1);
	i = 0;
	while (lst->bck)
	{
		lst = lst->bck;
		i++;
	}
	return (i);
}
