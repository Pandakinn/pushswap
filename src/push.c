/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:59:35 by darian            #+#    #+#             */
/*   Updated: 2022/01/21 16:09:55 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	pa(t_list **la, t_list **lb)
{
	if (!(*lb))
		return ;
	ft_putstr_fd("pa\n", 1);
	ft_lstadd_front(la, ft_lstnew((*lb)->content));
	ft_lstdelone(lb, ft_lstdelcontent);
}

void	pb(t_list **lb, t_list **la)
{
	if (!(*la))
		return ;
	ft_putstr_fd("pb\n", 1);
	ft_lstadd_front(lb, ft_lstnew((*la)->content));
	ft_lstdelone(la, ft_lstdelcontent);
}
