/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:59:29 by csamuro           #+#    #+#             */
/*   Updated: 2021/04/18 18:46:10 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int symbol)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = ft_strlen((char *)str);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)symbol)
			return (&str[i]);
		if (i == 0)
			return (NULL);
		i--;
	}
	return (NULL);
}
