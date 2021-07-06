#include "../../main_header.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_color	color_bias_step(t_color a, t_color b, int len)
{
	a.t = a.t - b.t;
	a.r = a.r - b.r;
	a.g = a.g - b.g;
	a.b = a.b - b.b;
	a.t = a.t / len;
	a.r = a.r / len;
	a.g = a.g / len;
	a.b = a.b / len;
	return (a);
}

t_color	*color_plus(t_color *a, t_color *bias)
{
	a->t += bias->t;
	a->r += bias->r;
	a->g += bias->g;
	a->b += bias->b;
	return (a);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || y >= HEIGHT || x >= WIDTH)
		return ;
	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_line(t_maps a, t_maps b, t_mlx *mlx)
{
	int		maxi;
	double	ctmp[2];
	t_maps	ss_knf;
	t_maps	vct;

	vct = a;
	ss_knf.pix.y = a.pix.y - b.pix.y;
	ss_knf.pix.x = a.pix.x - b.pix.x;
	ctmp[1] = 1;
	*ctmp = d_sgn(ss_knf.pix.y, 1) / d_sgn(ss_knf.pix.x, 1);
	maxi = max((int)d_sgn(ss_knf.pix.y, 1), (int)d_sgn(ss_knf.pix.x, 1));
	ss_knf.color = color_bias_step(b.color, a.color, maxi);
	if (*ctmp >= 1)
	{
		ctmp[1] = d_sgn(ss_knf.pix.x, 1) / d_sgn(ss_knf.pix.y, 1);
		*ctmp = 1;
	}
	if (ss_knf.pix.x > 0)
		ctmp[1] = -ctmp[1];
	if (ss_knf.pix.y > 0)
		*ctmp = - *ctmp;
	while (maxi-- > 0)
		my_mlx_pixel_put(mlx, (int)(vct.pix.x += ctmp[1]),
			(int)(vct.pix.y += *ctmp), color_get_c(
				*color_plus(&vct.color, &ss_knf.color)));
}
