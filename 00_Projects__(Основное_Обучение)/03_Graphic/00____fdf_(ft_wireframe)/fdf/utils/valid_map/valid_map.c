#include "../../main_header.h"

void	malloc_err(void *data, int size2, short ismust_exit)
{
	int		i;
	void	**data2;

	i = 0;
	if (data)
	{
		if (size2 == 0)
			free(data);
		if (size2 > 0)
		{
			data2 = (void **)data;
			while (size2-- > 0)
				free(data2);
			free(data2);
		}
	}
	if (ismust_exit)
	{
		ft_putstr_fd("err malloc\n", 0);
		exit(EXIT_FAILURE);
	}
}

char	*get_mapline(const char *path)
{
	char	*mapline;
	int		fd;
	int		size;
	char	buf;

	size = file_len(path);
	mapline = (char *)malloc(sizeof(char) * (size + 1));
	if (!mapline)
		malloc_err(NULL, 0, 1);
	fd = open(path, O_RDONLY);
	read(fd, mapline, size);
	while (!ft_isprint(mapline[--size]))
		mapline[size] = 0;
	return (mapline);
}

short	check_valid_len(t_maps *maps)
{
	int	len1;
	int	len2;

	maps_go(&maps, LEFT_TO_END);
	maps_go(&maps, UP_TO_END);
	len1 = maps_len_width(maps);
	maps = maps->down;
	while (maps)
	{
		len2 = maps_len_width(maps);
		if (len1 != len2)
		{
			maps_free_full(&maps);
			ft_putstr_fd("\\Found wrong line length. Exiting.\n", 1);
			exit(EXIT_FAILURE);
		}
		maps = maps->down;
	}
	return (1);
}

int	fd_count_newlines(int fd)
{
	int		count;
	char	buf;

	count = 0;
	while (read(fd, &buf, 1) > 0)
		if (buf == '\n')
			count++;
	close(fd);
	return (count);
}

t_maps	*hand_data_iarr(const char *path)
{
	t_maps	*maps;
	char	*mapline;
	char	**mapline2;

	mapline = get_mapline(path);
	mapline2 = ft_split(mapline, '\n');
	free(mapline);
	if (!mapline2)
	{
		write(1, "err malloc\n", 11);
		exit(EXIT_FAILURE);
	}
	maps = hand_iarr(mapline2);
	check_valid_len(maps);
	maps_init_coodinate(maps);
	return (maps);
}
