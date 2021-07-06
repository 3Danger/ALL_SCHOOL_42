/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:38:03 by csamuro           #+#    #+#             */
/*   Updated: 2021/04/19 22:26:35 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		sizebuf;
	int		i;
	char	*buf;

	sizebuf = count * size;
	i = 0;
	buf = NULL;
	buf = (char *)malloc(sizebuf);
	if (buf == NULL)
		return (NULL);
	while (i < sizebuf)
		buf[i++] = 0;
	return (buf);
}
