/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:53:34 by darian            #+#    #+#             */
/*   Updated: 2022/01/21 16:13:10 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	is_still_under_median(t_list *li, int median, int max)
{
	while (li != NULL)
	{
		if (li->content <= median && li->content > max)
			return (1);
		li = li->next;
	}
	return (0);
}

int	*convert_list_to_tab(t_list *li)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * ft_lstsize(li));
	while (li)
	{
		tab[i++] = li->content;
		li = li->next;
	}
	return (tab);
}

int	find_index_op_array(t_list **op_list, t_list *lb)
{
	int	i;
	int	min;

	i = 0;
	min = __INT_MAX__;
	while (i < ft_lstsize(lb))
	{
		if (op_list[i] && op_list[i]->content < min)
			min = op_list[i]->content;
		i++;
	}
	i = 0;
	while (i < ft_lstsize(lb))
	{
		if (op_list[i] && op_list[i]->content == min)
			return (i);
		i++;
	}
	return (0);
}

void	apply_operation(t_list **la, t_list **lb, t_list *op_list)
{
	if (op_list->content == RA)
		ra(la);
	if (op_list->content == RB)
		rb(lb);
	if (op_list->content == RR)
		rr(la, lb);
	if (op_list->content == RRA)
		rra(la);
	if (op_list->content == RRB)
		rrb(lb);
	if (op_list->content == RRR)
		rrr(la, lb);
	if (op_list->content == PA)
		pa(la, lb);
	if (op_list->content == PB)
		pb(lb, la);
	if (op_list->content == SA)
		sa(la);
	visualise_list(*la, *lb);
}

void	apply_array_operation(t_list **la, t_list **lb, int *max, int last_max)
{
	t_list	**op_list;
	t_tab	tab;
	int		i;
	int		size_arr;

	tab = (t_tab){convert_list_to_tab(*la),
		convert_list_to_tab(*lb), ft_lstsize(*la), ft_lstsize(*lb)};
	size_arr = ft_lstsize(*lb);
	op_list = gen_tab_of_operation(tab, max, last_max);
	i = find_index_op_array(op_list, *lb);
	if (tab.tab_b[i] > *max)
		*max = tab.tab_b[i];
	op_list[i] = op_list[i]->next;
	while (op_list[i])
	{
		apply_operation(la, lb, op_list[i]);
		op_list[i] = op_list[i]->next;
	}
	op_list = clear_tab(op_list, size_arr);
}
