#include "../../main_header.h"

t_pixel	get_start_point(int	width, int height)
{
	t_pixel	p;
	double	w;
	double	h;

	w = width;
	h = height;
	if (w < h)
	{
		p.x = 0;
		p.y = 0;
		p.z = WIDTH / w;
	}
	else
	{
		p.x = 0;
		p.y = 0;
		p.z = WIDTH / w;
	}
	return (p);
}

void	maps_coordinate(t_maps *maps, t_pixel point)
{
	t_maps	*tmp;
	t_maps	*tm2;
	t_pixel	p;

	p = point;
	tmp = maps;
	tm2 = maps;
	while (tmp)
	{
		while (tm2)
		{
			tm2->pix.x = p.x;
			tm2->pix.y = p.y;
			p.x += p.z;
			tm2 = tm2->right;
		}
		p.x = point.x;
		p.y += p.z;
		tmp = tmp->down;
		tm2 = tmp;
	}
}

void	maps_init_coodinate(t_maps *maps)
{
	int		width;
	int		height;
	t_maps	*tmp;

	width = 0;
	height = 0;
	maps_go(&maps, LEFT_TO_END);
	maps_go(&maps, UP_TO_END);
	tmp = maps;
	while (tmp)
	{
		height++;
		tmp = tmp->down;
	}
	width = maps_len_width(maps);
	maps_coordinate(maps, get_start_point(width, height));
}
