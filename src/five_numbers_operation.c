/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numbers_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:18:52 by darian            #+#    #+#             */
/*   Updated: 2022/01/24 18:20:04 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	top =la->content;
	mid = la->next->content;
	bot = la->next->next->content;
*/

#include "../include/pushswap.h"

t_list	*over_top_under_mid(t_range iter)
{
	t_list	*op;

	op = NULL;
	ft_lstadd_back(&op, ft_lstnew(2 + iter.start));
	while (iter.end < iter.start)
	{
		ft_lstadd_back(&op, ft_lstnew(RB));
		iter.end++;
	}
	ft_lstadd_back(&op, ft_lstnew(PA));
	ft_lstadd_back(&op, ft_lstnew(SA));
	return (op);
}

t_list	*over_mid_under_bot(t_range iter)
{
	t_list	*op;

	op = NULL;
	ft_lstadd_back(&op, ft_lstnew(3 + iter.start));
	while (iter.end < iter.start)
	{
		ft_lstadd_back(&op, ft_lstnew(RB));
		iter.end++;
	}
	ft_lstadd_back(&op, ft_lstnew(RA));
	ft_lstadd_back(&op, ft_lstnew(RA));
	ft_lstadd_back(&op, ft_lstnew(PA));
	return (op);
}

t_list	*over_bot(t_range iter)
{
	t_list	*op;

	op = NULL;
	ft_lstadd_back(&op, ft_lstnew(2 + iter.start));
	while (iter.end < iter.start)
	{
		ft_lstadd_back(&op, ft_lstnew(RB));
		iter.end++;
	}
	ft_lstadd_back(&op, ft_lstnew(PA));
	ft_lstadd_back(&op, ft_lstnew(RA));
	return (op);
}

t_list	*over_top(t_range iter)
{
	t_list	*op;

	op = NULL;
	ft_lstadd_back(&op, ft_lstnew(1 + iter.start));
	while (iter.end < iter.start)
	{
		ft_lstadd_back(&op, ft_lstnew(RB));
		iter.end++;
	}
	ft_lstadd_back(&op, ft_lstnew(PA));
	return (op);
}

t_list	**operation_five_numbers_three_la(t_list *la, t_list *lb)
{
	t_range	iter;
	t_list	**op;

	op = malloc(sizeof(t_list *) * ft_lstsize(lb));
	iter.start = 0;
	while (lb)
	{
		iter.end = 0;
		if (lb->content > la->content && lb->content < la->next->content)
			op[iter.start] = over_top_under_mid(iter);
		else if (lb->content > la->next->content
			&& lb->content < la->next->next->content)
			op[iter.start] = over_mid_under_bot(iter);
		else if (lb->content > la->next->next->content)
			op[iter.start] = over_bot(iter);
		else
			op[iter.start] = over_top(iter);
		lb = lb->next;
		iter.start++;
	}
	return (op);
}
