/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:53:39 by dasereno          #+#    #+#             */
/*   Updated: 2022/01/04 19:14:18 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstdelindex(t_list *lst, void (*del)(int *), int index)
{
	int		i;
	t_list	*prev;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	i = 0;
	while (lst != NULL && i != index - 1)
	{
		prev = lst;
		lst = lst->next;
		i++;
	}
	if (i < index - 1)
		return ;
	tmp = prev->next;
	prev->next = lst->next;
	(*del)(&tmp->content); 
	free(tmp);
	tmp = NULL;
}
