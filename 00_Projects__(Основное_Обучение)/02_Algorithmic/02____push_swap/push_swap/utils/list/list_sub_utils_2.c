#include "list.h"

void	lgo_back(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	while ((*stack)->bck)
		(*stack) = (*stack)->bck;
}

void	linit_bk(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp->nxt)
	{
		tmp->nxt->bck = tmp;
		tmp = tmp->nxt;
	}
	tmp = lmax_min(lst, -1, 0);
	while (tmp->nxt_ordr)
	{
		tmp->nxt_ordr->bck_ordr = tmp;
		tmp = tmp->nxt_ordr;
	}
}

void	linit(t_stack *lst)
{
	t_stack	*t1;

	if (!lst)
		return ;
	t1 = lmax_min(lst, DOWN, 0);
	while (1)
	{
		t1->nxt_ordr = lnext(t1, UP, 0);
		if (!t1->nxt_ordr)
			break ;
		t1 = t1->nxt_ordr;
	}
	linit_bk(lst);
}

t_stack	*lnext(t_stack *el, short updown, int div)
{
	t_stack	*t1;
	t_stack	*t2;

	if (!el)
		return (NULL);
	t1 = NULL;
	t2 = el;
	lgo_back(&t2);
	while (t2->div != div)
		t2 = t2->nxt;
	while (t2)
	{
		if ((updown == UP) && (t2->div == div) && (el->var < t2->var
				&& (!t1 || t1->var > t2->var)))
			t1 = t2;
		if ((updown == DOWN) && (t2->div == div) && (el->var > t2->var
				&& (!t1 || t1->var < t2->var)))
			t1 = t2;
		t2 = t2->nxt;
	}
	return (t1);
}
