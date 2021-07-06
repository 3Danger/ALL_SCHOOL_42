#ifndef ALG_UTILS_PROTO_H
# define ALG_UTILS_PROTO_H
# include "../push_swap.h"
void	ret_state(t_stack **a, char **ops);
void	come(t_stack **base, t_stack *el, char **ops);
short	check_sort(t_stack	*lst);
void	set_mark_ifsorted(t_stack **a);
void	magic_algorithm(t_stack **a, t_stack **b, char **ops);
short	to_short_very_smallsort(t_stack **a, char **ops, int len);
void	alg_very_smallsort(t_stack **a, char **ops, int len);
void	algorithm_smallsort(t_stack **a, t_stack **b, char **ops);
void	algorithm_bigsort(t_stack **a, t_stack **b, char **ops);
#endif