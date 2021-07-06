#include "../../main_header.h"

void	short_mps_fr(t_maps **n, t_maps **m)
{
	*n = *m;
	*m = (*m)->right;
	free(*n);
}

void	maps_free_full(t_maps **m)
{
	t_maps	*n;

	if (!m || !*m)
		return ;
	maps_go(m, LEFT_TO_END);
	maps_go(m, UP_TO_END);
	while (*m)
	{
		while ((*m)->right)
			short_mps_fr(&n, m);
		if ((*m)->down)
		{
			n = (*m);
			maps_go(m, DOWN);
			maps_go(m, LEFT_TO_END);
			free(n);
		}
		else
		{
			free((*m));
			*m = NULL;
		}
	}
}
