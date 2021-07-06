#include "../main_header.h"

t_pixel	get_bias_origin(t_maps *maps)
{
	t_maps	*tmp[2];
	t_pixel	start;
	t_pixel	end;

	tmp[0] = (tmp[1] = maps);
	end.x = (end.y = (start.x = (start.y = 0)));
	while (*tmp)
	{
		while (tmp[1])
		{
			if (tmp[1]->pix.y < start.y)
				start.y = tmp[1]->pix.y;
			if (tmp[1]->pix.x < start.x)
				start.x = tmp[1]->pix.x;
			if (tmp[1]->pix.y > end.y)
				end.y = tmp[1]->pix.y;
			if (tmp[1]->pix.x > end.x)
				end.x = tmp[1]->pix.x;
			tmp[1] = tmp[1]->right;
		}
		tmp[1] = (tmp[0] = tmp[0]->down);
	}
	end.x = ((mid_point(WIDTH / 2, end.x, start.x)));
	end.y = ((mid_point(HEIGHT / 2, end.y, start.y)));
	return (end);
}

void	magic_cissin(t_maps	*el, int dist_pix, double z)
{
	el->pix.x = (el->pix.x - el->pix.y) * cos(ROTATE);
	el->pix.y = (el->pix.x + el->pix.y) * sin(ROTATE);
	if (z)
		el->pix.y -= (el->height / z * 50);
}

void	begin_all_map_el(t_maps *maps, double z)
{
	int		dist_pix;
	t_maps	*tmp;
	t_maps	*tm2;

	tmp = maps;
	tm2 = maps;
	dist_pix = maps->right->pix.x - maps->pix.x;
	while (tmp)
	{
		while (tm2)
		{
			magic_cissin(tm2, dist_pix, z);
			tm2->pix.y *= STRETH_HEIGHT;
			tm2->pix.x *= STRETH_WIDTH;
			tm2 = tm2->right;
		}
		tmp = tmp->down;
		tm2 = tmp;
	}
}

double	max_height_bias(t_maps *maps, double limit)
{
	double	i;
	int		maximum;
	t_maps	*tmp;
	t_maps	*tm2;

	tmp = (tm2 = maps);
	maximum = 0;
	while (tmp)
	{
		while (tm2)
		{
			if (maximum < tm2->height)
				maximum = tm2->height;
			tm2 = tm2->right;
		}
		tm2 = (tmp = tmp->down);
	}
	i = maximum;
	while (maximum / i < limit)
		i -= 0.1;
	while (maximum / i > limit)
		i += 0.1;
	return (i);
}

void	isometric(t_maps *maps)
{
	double	z;
	t_pixel	bias;
	t_maps	*tmp;
	t_maps	*tm2;

	tmp = maps;
	tm2 = maps;
	z = max_height_bias(maps, 5);
	begin_all_map_el(maps, z);
	bias = get_bias_origin(maps);
	while (tmp)
	{
		while (tm2)
		{
			tm2->pix.x += bias.x;
			tm2->pix.y += bias.y;
			tm2 = tm2->right;
		}
		tmp = tmp->down;
		tm2 = tmp;
	}
}
