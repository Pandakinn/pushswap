/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:53:39 by dasereno          #+#    #+#             */
/*   Updated: 2022/01/10 01:32:52 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **lst, void (*del)(int *))
{
	t_list	*tmp;
	
	if (!(*lst) || !del)
		return ;
	tmp = (*lst);
	*lst = (*lst)->next;
	(*del)(&tmp->content);
	free(tmp);
	tmp = NULL;
}
