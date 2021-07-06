/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:51:01 by csamuro           #+#    #+#             */
/*   Updated: 2021/04/21 18:00:43 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_header.h"

char	*ft_strchr(const char *s, int symbol)
{
	return ((char *)ft_memchr((char *)s, symbol, ft_strlen(s) + 1));
}
