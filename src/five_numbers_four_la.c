/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numbers_four_la.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:30:05 by darian            #+#    #+#             */
/*   Updated: 2022/01/24 18:31:01 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_list	*under_min(t_list *la, int min, int i)
{
	int		index;
	t_list	*op;

	op = NULL;
	index = find_index_list(la, min);
	if (index == 3)
	{
		ft_lstadd_back(&op, ft_lstnew(RRA));
		i = 1;
	}
	else
	{
		while (i < index)
		{
			ft_lstadd_back(&op, ft_lstnew(RA));
			i++;
		}
	}
	ft_lstadd_back(&op, ft_lstnew(PA));
	ft_lstadd_front(&op, ft_lstnew(1 + i));
	return (op);
}

t_list	*over_max(t_list *la, int max, int i)
{
	int		index;
	t_list	*op;

	op = NULL;
	index = find_index_list(la, max) + 1;
	while (i < ft_lstsize(la) - index)
	{
		ft_lstadd_back(&op, ft_lstnew(RRA));
		i++;
	}
	ft_lstadd_back(&op, ft_lstnew(PA));
	ft_lstadd_front(&op, ft_lstnew(1 + i));
	return (op);
}

t_list	*between_min_max(t_list	*la, int nb, int i)
{
	int		index;
	t_list	*op;

	op = NULL;
	index = find_index_over_list(la, nb);
	if (index == 3)
	{
		ft_lstadd_back(&op, ft_lstnew(RRA));
		i = 1;
	}
	else
	{
		while (i < index)
		{
			ft_lstadd_back(&op, ft_lstnew(RA));
			i++;
		}
	}
	ft_lstadd_back(&op, ft_lstnew(PA));
	ft_lstadd_front(&op, ft_lstnew(1 + i));
	return (op);
}

t_list	*operation_five_numbers_four_la(t_list *la,
t_list *lb, int max, int min)
{
	t_list	*op;
	int		nb;
	int		i;

	i = 0;
	op = NULL;
	nb = lb->content;
	if (nb < min)
		op = under_min(la, min, i);
	else if (nb > max)
		op = over_max(la, max, i);
	else
		op = between_min_max(la, nb, i);
	return (op);
}
