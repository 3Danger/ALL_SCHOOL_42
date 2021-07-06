/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:06:19 by csamuro           #+#    #+#             */
/*   Updated: 2021/04/20 17:09:50 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	long		res;
	int			len;
	long		minus;

	i = 0;
	res = 0;
	len = 0;
	minus = 1;
	if (ft_strchr("+-0123456789 \n\t\v\r\f", str[i]))
	{
		while (ft_strchr(" \n\t\v\r\f", str[i]))
			i++;
		if (str[i] == '-' || str[i] == '+')
			if (str[i++] == '-')
				minus = -1;
		while (ft_isdigit(str[i + len]) && str[i + len])
			res = res * 10 + str[i + len++] - '0';
	}
	return ((int)(res * minus));
}
