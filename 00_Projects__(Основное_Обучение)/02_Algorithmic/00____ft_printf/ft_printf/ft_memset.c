/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:33:36 by csamuro           #+#    #+#             */
/*   Updated: 2021/04/16 17:05:09 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_header.h"

void	*ft_memset(void *dest, int c, size_t size)
{
	size_t			i;
	unsigned char	*de;

	i = 0;
	de = (unsigned char *)dest;
	while (i < size)
		de[i++] = c;
	return (dest);
}
