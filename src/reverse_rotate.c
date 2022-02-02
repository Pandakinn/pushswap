/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:10:09 by darian            #+#    #+#             */
/*   Updated: 2022/01/21 16:11:01 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	rra(t_list	**li)
{
	int	tmp;

	if (!(*li))
		return ;
	ft_putstr_fd("rra\n", 1);
	tmp = ft_lstlast(*li)->content;
	ft_lstdelindex(*li, ft_lstdelcontent, ft_lstsize(*li));
	ft_lstadd_front(li, ft_lstnew(tmp));
}

void	rrb(t_list	**li)
{
	int	tmp;

	if (!(*li))
		return ;
	ft_putstr_fd("rrb\n", 1);
	tmp = ft_lstlast(*li)->content;
	ft_lstdelindex(*li, ft_lstdelcontent, ft_lstsize(*li));
	ft_lstadd_front(li, ft_lstnew(tmp));
}

void	rrr(t_list	**la, t_list **lb)
{
	int	tmp;
	int	is_writed;

	is_writed = 0;
	if ((*la))
	{
		ft_putstr_fd("rrr\n", 1);
		is_writed = 1;
		tmp = ft_lstlast(*la)->content;
		ft_lstdelindex(*la, ft_lstdelcontent, ft_lstsize(*la));
		ft_lstadd_front(la, ft_lstnew(tmp));
	}
	if ((*lb))
	{
		if (!is_writed)
			ft_putstr_fd("rrr\n", 1);
		tmp = ft_lstlast(*lb)->content;
		ft_lstdelindex(*lb, ft_lstdelcontent, ft_lstsize(*lb));
		ft_lstadd_front(lb, ft_lstnew(tmp));
	}
}
