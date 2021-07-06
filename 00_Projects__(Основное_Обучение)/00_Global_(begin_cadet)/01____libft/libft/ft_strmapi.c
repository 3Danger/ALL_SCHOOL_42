/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:05:27 by csamuro           #+#    #+#             */
/*   Updated: 2021/04/21 14:06:14 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	res = ft_strdup(s);
	if (res == NULL)
		return (NULL);
	while (s[i])
	{
		res[i] = (*f)(i, res[i]);
		i++;
	}
	return (res);
}
