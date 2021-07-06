/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:30:13 by csamuro           #+#    #+#             */
/*   Updated: 2021/04/17 16:43:16 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_header.h"

void	*ft_memchr(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while (i < n)
	{
		if ((unsigned char)c == s[i])
			return (&s[i]);
		i++;
	}
	return (NULL);
}
