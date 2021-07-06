/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:57:34 by csamuro           #+#    #+#             */
/*   Updated: 2021/04/21 15:29:06 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_header.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	len;
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	len = ft_strlen(s);
	while (i < len)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
