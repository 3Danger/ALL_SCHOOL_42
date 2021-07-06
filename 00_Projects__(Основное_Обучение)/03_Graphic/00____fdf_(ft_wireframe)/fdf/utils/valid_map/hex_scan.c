#include "../../main_header.h"

t_color	color_set(int t, int r, int g, int b)
{
	t_color	color;

	color.t = t;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

/*
* FF EE DD CC >> 				 = 00 00 00 FF
* FF EE DD CC >> - 00 00 FF 00 = 00 00 00 EE
* FF EE DD CC >> - 00 FF EE 00 = 00 00 00 DD
* FF EE DD CC >> - FF EE DD 00 = 00 00 00 CC
*/

t_color	color_get_i(int	res_hex)
{
	t_color	color;
	int		tmp;

	tmp = res_hex;
	color.t = res_hex >> 8 * 3;
	color.r = (res_hex >> 8 * 2) - ((res_hex >> (8 * 3)) << 8);
	color.g = (res_hex >> 8) - ((res_hex >> (8 * 2)) << 8);
	color.b = (res_hex) - ((res_hex >> 8) << 8);
	return (color);
}

int	color_get_c(t_color color)
{
	int	res;

	res = color.t;
	res <<= 8;
	res += color.r;
	res <<= 8;
	res += color.g;
	res <<= 8;
	res += color.b;
	return (res);
}

t_color	get_hex_ishex(char *str)
{
	int		i;
	int		res_hex;
	t_color	color;

	i = 0;
	res_hex = 0;
	color = color_set(0, 0xff, 0xff, 0xff);
	if (str && *str++ == ',' && *str++ == '0' && *str++ == 'x')
	{
		while (ft_isdigit(str[i]) || (str[i] > 64 && str[i] < 71)
			|| (str[i] > 96 && str[i] < 103))
		{
			if (ft_isdigit(str[i]))
				res_hex = res_hex * 16 + (str[i] - 48);
			if ((str[i] > 64 && str[i] < 71))
				res_hex = res_hex * 16 + (str[i] - 55);
			if ((str[i] > 96 && str[i] < 103))
				res_hex = res_hex * 16 + (str[i] - 87);
			i++;
		}
		color = color_get_i(res_hex);
	}
	return (color);
}
