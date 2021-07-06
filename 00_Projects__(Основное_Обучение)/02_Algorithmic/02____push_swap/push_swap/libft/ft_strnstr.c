/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 21:49:10 by csamuro           #+#    #+#             */
/*   Updated: 2021/04/18 22:20:50 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	nlen;

	nlen = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && n-- >= nlen)
	{
		if (*haystack == *needle)
			if (!ft_memcmp(haystack, needle, nlen))
				return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
