#ifndef LIST_H
# define LIST_H
# define UP 1
# define DOWN -1
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
typedef struct s_stack
{
	int				var;
	struct s_stack	*nxt;
	struct s_stack	*nxt_ordr;
	struct s_stack	*bck;
	struct s_stack	*bck_ordr;
	short			stack;
	int				div;
}	t_stack;

t_stack	*lnew_el(int val);
short	ladd_front(t_stack **lst, t_stack *el);
t_stack	*lmax_min(t_stack *lst, short updown, int div);
void	linit(t_stack *lst);
void	lfree(t_stack **lst);
void	lfree_full(t_stack **lst);
int		llen(t_stack *lst, int div);
int		lindex(t_stack *lst);
int		lindex_sort(t_stack *lst);
t_stack	*lget_byindex(t_stack *lst, int i);
t_stack	*lget_last(t_stack *lst);
t_stack	*ldiv_max_el(t_stack *lst);
t_stack	*ldiv_max_el_glob(t_stack *lst);
t_stack	*lget_mid(t_stack *lst, int div);
void	lgo_back(t_stack **stack);
void	linit(t_stack *lst);
t_stack	*lnext(t_stack *el, short updown, int div);
void	l_iarr_convert(t_stack **out, int *iarr, int size);
t_stack	*lnext_ud_mid(t_stack *start, int mid, int updown, int div);

#endif
