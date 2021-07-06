/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 11:46:21 by csamuro           #+#    #+#             */
/*   Updated: 2021/04/18 12:49:55 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_header.h"

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	i;
	unsigned int	slen;

	if (src == NULL)
		return (0);
	slen = ft_strlen(src);
	if (dstsize == 0)
		return (slen);
	i = 0;
	dstsize--;
	while (i < dstsize)
	{
		if (!src[i])
			break ;
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}
