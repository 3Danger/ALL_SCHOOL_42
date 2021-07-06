/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:18:36 by csamuro           #+#    #+#             */
/*   Updated: 2021/04/20 20:31:14 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_header.h"

static unsigned int	countto(char const *str, char c)
{
	unsigned int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

static unsigned int	cntsplits(char const *str, char c)
{
	unsigned int	i;
	unsigned int	sp;

	i = 0;
	sp = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if (str[i] != c)
		{
			sp++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (sp);
}

static char	**relloc(char **trash, int size)
{
	while (size > 0)
	{
		size--;
		free(trash[size]);
	}
	free(trash);
	return (NULL);
}

static char	*skipper(char *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	unsigned int	index[2];
	unsigned int	blocks;

	if (!s)
		return (NULL);
	index[0] = 0;
	index[1] = 0;
	blocks = cntsplits(s, c);
	res = (char **)malloc(sizeof(char *) * (blocks + 1));
	if (!res)
		return (NULL);
	while (index[0] < blocks)
	{
		s = skipper((char *)s, c);
		res[index[0]] = (char *)malloc(sizeof(char) * (countto(s, c) + 1));
		if (!res[index[0]])
			return (relloc(res, index[0]));
		res[index[0]++][countto(s, c)] = '\0';
		while (*s != c && *s)
			res[index[0] - 1][index[1]++] = *s++;
		index[1] = 0;
	}
	res[blocks] = NULL;
	return (res);
}
