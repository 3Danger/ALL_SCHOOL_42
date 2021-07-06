#include "../../main_header.h"

int	maps_len_width(t_maps *maps)
{
	int	len;

	len = 0;
	maps_go(&maps, LEFT_TO_END);
	while (maps)
	{
		len++;
		maps = maps->right;
	}
	return (len);
}

t_maps	*maps_new_el(int height, t_color color)
{
	t_maps	*el;

	el = (t_maps *)malloc(sizeof(t_maps));
	if (!el)
		return (NULL);
	el->color = color;
	el->height = height;
	el->up = NULL;
	el->down = NULL;
	el->right = NULL;
	el->left = NULL;
	el->pix.x = 0;
	el->pix.y = 0;
	return (el);
}

short	maps_add_bind(t_maps **maps, t_maps *el)
{
	if (!el)
		return (0);
	if (!*maps)
	{
		*maps = el;
		return (1);
	}
	while ((*maps)->right)
		(*maps) = (*maps)->right;
	(*maps)->right = el;
	el->left = (*maps);
	(*maps) = el;
	return (1);
}

void	maps_go(t_maps **maps, short go)
{
	t_maps	*tmp;

	if (!maps || !*maps)
		return ;
	tmp = *maps;
	while (1)
	{
		if ((go == LEFT_TO_END || go == LEFT) && tmp->left)
			tmp = tmp->left;
		if ((go == RIGHT_TO_END || go == RIGHT) && tmp->right)
			tmp = tmp->right;
		if ((go == UP_TO_END || go == UP) && tmp->up)
			tmp = tmp->up;
		if ((go == DOWN_TO_END || go == DOWN) && tmp->down)
			tmp = tmp->down;
		if ((go == LEFT_TO_END && !tmp->left)
			|| (go == RIGHT_TO_END && !tmp->right)
			|| (go == UP_TO_END && !tmp->up)
			|| (go == DOWN_TO_END && !tmp->down)
			|| go == LEFT || go == RIGHT || go == UP || go == DOWN)
			break ;
	}
	*maps = tmp;
}

static void	mapsffdown(t_maps **maps)
{
	t_maps	*n;
	t_maps	*m;

	m = *maps;
	if (m->down)
	{
		n = m;
		m = m->down;
		free(n);
	}
	*maps = m;
}
