#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define AB 0
# define A 1
# define B 2
# define P 3
# define S 4
# define R 5
# define RR 6
# include "utils/list/list.h"
# include "libft/libft.h"

int		*handler_input(const char **argv, int *size);
int		ops_add(char **ops, short operarion, short stack);
void	ops_print(char **ops);
void	ops_free(char **ops);
short	ss(t_stack	**lst, char **ops);
short	pp(t_stack **from, t_stack **to, char **ops);
short	rr(t_stack **lst, short updown, char **ops);
void	magic_algorithm(t_stack **a, t_stack **b, char **ops);
void	algorithm(t_stack **a, char **ops);

#endif