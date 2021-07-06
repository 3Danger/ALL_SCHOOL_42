/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 22:25:25 by csamuro           #+#    #+#             */
/*   Updated: 2021/04/20 22:26:08 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_header.h"

static void	swapstr(char *str)
{
	size_t	len;
	size_t	i;
	char	c;

	i = 0;
	len = ft_strlen(str);
	while (i < len--)
	{
		c = str[i];
		str[i] = str[len];
		str[len] = c;
		i++;
	}
}

static char	*signchange(char *str, int isminus)
{
	if (isminus)
		return (ft_strjoin("-", str));
	else
		return (ft_strdup(str));
}

char	*ft_itoa(int n)
{
	short	isminus;
	char	tmp[11];
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	isminus = 0;
	if (n < 0)
	{
		isminus = 1;
		n = -n;
	}
	while (n > 0)
	{
		tmp[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	tmp[i] = '\0';
	swapstr(tmp);
	return (signchange(tmp, isminus));
}

char	*ft_uitoa(unsigned int n)
{
	char	tmp[11];
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	while (n > 0)
	{
		tmp[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	tmp[i] = '\0';
	swapstr(tmp);
	return (ft_strdup(tmp));
}
