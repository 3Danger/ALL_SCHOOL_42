#include "../main_header.h"

void	run_nigga(t_maps *maps, t_mlx *mlx)
{
	t_maps	*tmp;
	t_maps	*tm2;

	tmp = maps;
	tm2 = maps;
	while (tmp)
	{
		while (tm2->right)
		{
			print_line(*tm2, *tm2->right, mlx);
			if (tm2->down)
				print_line(*tm2, *tm2->down, mlx);
			tm2 = tm2->right;
		}
		if (tm2->down)
			print_line(*tm2, *tm2->down, mlx);
		tmp = tmp->down;
		tm2 = tmp;
	}
}
