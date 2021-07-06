/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamuro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 22:39:11 by csamuro           #+#    #+#             */
/*   Updated: 2021/04/23 22:39:25 by csamuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*entr;

	entr = *lst;
	while (entr)
	{
		tmp = entr->next;
		if (del)
			del(entr->content);
		free(entr);
		entr = tmp;
	}
	*lst = NULL;
}
