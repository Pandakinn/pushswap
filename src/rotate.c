/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:29:06 by darian            #+#    #+#             */
/*   Updated: 2022/01/21 16:10:30 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	ra(t_list	**li)
{
	int	tmp;

	if (!(*li))
		return ;
	ft_putstr_fd("ra\n", 1);
	tmp = (*li)->content;
	ft_lstdelone(li, ft_lstdelcontent);
	ft_lstadd_back(li, ft_lstnew(tmp));
}

void	rb(t_list	**li)
{
	int	tmp;

	if (!(*li))
		return ;
	ft_putstr_fd("rb\n", 1);
	tmp = (*li)->content;
	ft_lstdelone(li, ft_lstdelcontent);
	ft_lstadd_back(li, ft_lstnew(tmp));
}

void	rr(t_list	**la, t_list **lb)
{
	int	tmp;
	int	is_writed;

	is_writed = 0;
	if ((*la))
	{
		ft_putstr_fd("rr\n", 1);
		is_writed = 1;
		tmp = (*la)->content;
		ft_lstdelone(la, ft_lstdelcontent);
		ft_lstadd_back(la, ft_lstnew(tmp));
	}
	if ((*lb))
	{
		if (!is_writed)
			ft_putstr_fd("rr\n", 1);
		tmp = (*lb)->content;
		ft_lstdelone(lb, ft_lstdelcontent);
		ft_lstadd_back(lb, ft_lstnew(tmp));
	}
}
