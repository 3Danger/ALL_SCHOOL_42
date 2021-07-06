#include "../../main_header.h"

t_maps	*short_hsub(t_maps **maps, char **sub, int *len, int *i)
{
	*len = 0;
	(*i) = -1;
	while (sub && sub[*len])
		(*len)++;
	if (*maps)
	{
		maps_go(maps, LEFT_TO_END);
		maps_go(maps, DOWN_TO_END);
	}
	return (*maps);
}

void	case_fall(t_maps **maps)
{
	maps_free_full(maps);
	ft_putstr_fd("err malloc\n", 0);
	exit(EXIT_FAILURE);
}

void	sub_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
}

void	hand_sub(t_maps **maps, char *str)
{
	t_maps	*map_nxt;
	t_maps	*tmp;
	char	**sub;
	int		len;
	int		i;

	tmp = NULL;
	sub = ft_split(str, ' ');
	map_nxt = short_hsub(maps, sub, &len, &i);
	while (++i < len)
	{
		if (!maps_add_bind(&tmp, maps_new_el(ft_atoi(sub[i]),
					get_hex_ishex(ft_strchr(sub[i], ',')))))
			case_fall(maps);
		if (map_nxt)
		{
			map_nxt->down = tmp;
			tmp->up = map_nxt;
			map_nxt = map_nxt->right;
		}
	}
	if (!*maps)
		*maps = tmp;
	sub_free(sub);
}

t_maps	*hand_iarr(char **mapline2)
{
	char	**sub_map;
	t_maps	*maps_res;
	t_maps	*tmp;
	int		len;
	int		i;

	i = 0;
	len = 0;
	maps_res = NULL;
	while (mapline2[len])
		len++;
	hand_sub(&maps_res, mapline2[i++]);
	while (i < len)
	{
		hand_sub(&maps_res, mapline2[i++]);
		maps_res = maps_res->down;
	}
	maps_go(&maps_res, LEFT_TO_END);
	maps_go(&maps_res, UP_TO_END);
	sub_free(mapline2);
	return (maps_res);
}
