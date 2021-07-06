#include "list.h"
#include "../../push_swap.h"

int	lindex_sort(t_stack *lst)
{
	int	i;

	if (!lst)
		return (-1);
	i = 0;
	while (lst->bck_ordr)
	{
		lst = lst->bck_ordr;
		i++;
	}
	return (i);
}

t_stack	*lget_byindex(t_stack *lst, int i)
{
	if (!lst)
		return (NULL);
	lgo_back(&lst);
	if (i > llen(lst, INT_MIN) - 1)
		return (NULL);
	while (lst->nxt && i--)
		lst = lst->nxt;
	return (lst);
}

t_stack	*lget_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	if (llen(lst, INT_MIN) == 0)
		return (NULL);
	while (lst->nxt)
		lst = lst->nxt;
	return (lst);
}

void	lfree(t_stack **lst)
{
	t_stack	*nxt;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		nxt = *lst;
		*lst = (*lst)->nxt;
		free(nxt);
	}
	*lst = NULL;
}

void	lfree_full(t_stack **lst)
{
	t_stack	*nxt;

	if (!lst || !*lst)
		return ;
	while ((*lst)->bck_ordr)
		(*lst) = (*lst)->bck_ordr;
	while (*lst)
	{
		nxt = *lst;
		*lst = (*lst)->nxt_ordr;
		free(nxt);
	}
	*lst = NULL;
}
