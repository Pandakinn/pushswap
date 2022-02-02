/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:07:02 by darian            #+#    #+#             */
/*   Updated: 2022/01/21 16:11:04 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	sa(t_list **li)
{
	int	tmp;

	if (!(*li) || !(*li)->next)
		return ;
	ft_putstr_fd("sa\n", 1);
	tmp = (*li)->content;
	(*li)->content = (*li)->next->content;
	(*li)->next->content = tmp;
}

void	sb(t_list **li)
{
	int	tmp;

	if (!(*li) || !(*li)->next)
		return ;
	ft_putstr_fd("sb\n", 1);
	tmp = (*li)->content;
	(*li)->content = (*li)->next->content;
	(*li)->next->content = tmp;
}

void	ss(t_list **la, t_list **lb)
{
	int	tmp;
	int	is_writed;

	is_writed = 0;
	if ((*la) && (*la)->next)
	{
		ft_putstr_fd("ss\n", 1);
		is_writed = 1;
		tmp = (*la)->content;
		(*la)->content = (*la)->next->content;
		(*la)->next->content = tmp;
	}
	if ((*lb) && (*lb)->next)
	{
		if (!is_writed)
			ft_putstr_fd("ss\n", 1);
		tmp = (*lb)->content;
		(*lb)->content = (*lb)->next->content;
		(*lb)->next->content = tmp;
	}
}
