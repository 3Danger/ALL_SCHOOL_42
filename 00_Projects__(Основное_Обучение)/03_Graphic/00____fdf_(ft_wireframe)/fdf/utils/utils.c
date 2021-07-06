#include "../main_header.h"

double	get_dmax(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	get_dmin(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	d_sgn(double val, short sign)
{
	if ((sign > 0 && val < 0) || (sign < 0 && val > 0))
		return (-val);
	return (val);
}

double	mid_point(int hw, double a, double b)
{
	double	c;

	if (a > b)
	{
		c = a;
		a = b;
		b = c;
	}
	while (a < b)
	{
		a += 1;
		b -= 1;
	}
	while (a < 0)
	{
		a += 1;
		hw += 1;
	}
	return (hw - a);
}

int	file_len(const char *path)
{
	int		size;
	int		len;
	int		fd;
	char	buf;

	fd = -2;
	size = 1;
	len = ft_strlen(path);
	if (path[--len] == 'f' && path[--len] == 'd'
		&& path[--len] == 'f' && path[--len] == '.')
		fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		if (fd == -1)
			write(1, "err open file\n", 14);
		else
			write(1, "err path to file\n", 17);
		exit(EXIT_FAILURE);
	}
	while (read(fd, &buf, 1) > 0)
		size++;
	close(fd);
	return (size);
}
