#include "../../push_swap.h"

short	ss(t_stack	**lst, char **ops)
{
	t_stack	*tmp;

	if (!lst || !*lst || !(*lst)->nxt)
		return (1);
	tmp = (*lst)->nxt;
	(*lst)->nxt = (*lst)->nxt->nxt;
	if ((*lst)->nxt)
		(*lst)->nxt->bck = (*lst);
	(*lst)->bck = tmp;
	tmp->nxt = (*lst);
	tmp->bck = NULL;
	(*lst) = tmp;
	ops_add(ops, S, (*lst)->stack);
	return (1);
}

short	pp(t_stack **from, t_stack **to, char **ops)
{
	t_stack	*tmp;

	if (!from || !*from || !to)
		return (1);
	tmp = *from;
	(*from) = (*from)->nxt;
	if ((*from))
		(*from)->bck = NULL;
	else
		(*from) = NULL;
	tmp->nxt = *to;
	if (*to)
		(*to)->bck = tmp;
	*to = tmp;
	if ((*to)->stack == A)
		(*to)->stack = B;
	else
		(*to)->stack = A;
	ops_add(ops, P, (*to)->stack);
	return (1);
}

static void	rr_short(int updown, t_stack **lst, char **ops)
{
	t_stack	*srt;
	t_stack	*tmp;
	t_stack	*end;

	srt = *lst;
	end = lget_last(*lst);
	if (updown == UP)
	{
		tmp = srt->nxt;
		tmp->bck = NULL;
		end->nxt = srt;
		srt->bck = end;
		srt->nxt = NULL;
		*lst = tmp;
		ops_add(ops, R, (*lst)->stack);
		return ;
	}
	tmp = end->bck;
	tmp->nxt = NULL;
	end->bck = NULL;
	end->nxt = srt;
	srt->bck = end;
	*lst = end;
	ops_add(ops, RR, (*lst)->stack);
}

short	rr(t_stack **lst, short updown, char **ops)
{
	if (!lst || !*lst || !(*lst)->nxt)
		return (1);
	if (!(*lst)->nxt->nxt)
		ss(lst, ops);
	else
		rr_short(updown, lst, ops);
	return (1);
}
