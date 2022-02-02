/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:29:37 by darian            #+#    #+#             */
/*   Updated: 2022/01/21 16:19:38 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	push_swap_list_sorted(t_list **la, t_list **lb, t_list *op)
{
	int	max;
	int	size;
	int	*tab;

	if (list_is_sorted(*la))
	{
		max = find_max_list(*la);
		tab = convert_list_to_tab(*la);
		size = ft_lstsize(*la);
		if (find_index_tab(tab, size, max) + 1
			> (size / 2) + (size % 2))
			op = create_list_while(RRA, size
					- ((find_index_tab(tab, size, max) + 1)));
		else
			op = create_list_while(RA,
					find_index_tab(tab, size, max) + 1);
		while (op)
		{
			apply_operation(la, lb, op);
			op = op->next;
		}
		return (1);
	}
	return (0);
}

void	push_swap_median_not_first(int max, t_list **la, t_list **lb)
{
	int		*tab;
	t_list	*op;

	if (max != -2147483648)
	{
		tab = convert_list_to_tab(*la);
		op = create_list_while(RRA, ft_lstsize(*la)
				- (find_index_tab(tab, ft_lstsize(*la), max) + 1));
		while (op)
		{
			apply_operation(la, lb, op);
			op = op->next;
		}
		tab = NULL;
	}
}

void	push_swap_median(t_list **la, t_list **lb, int max, int *size)
{
	int		*arr;
	int		median;

	arr = generate_median_array(*la, max, size);
	median = find_median(arr, *size);
	while (is_still_under_median(*la, median, max))
	{
		if ((*la)->content <= median && (*la)->content > max)
		{
			pb(lb, la);
			visualise_list(*la, *lb);
		}
		else
		{
			ra(la);
			visualise_list(*la, *lb);
		}
	}
	push_swap_median_not_first(max, la, lb);
	pa(la, lb);
	free(arr);
	visualise_list(*la, *lb);
}

void	push_swap_sorting(int *max, t_list **la, t_list **lb, int size)
{
	int		last_max;
	int		*tab;
	t_list	*op;

	last_max = *max;
	*max = (*la)->content;
	while (*lb)
		apply_array_operation(la, lb, max, last_max);
	tab = convert_list_to_tab(*la);
	if (find_index_tab(tab, size, *max) + 1
		> (size / 2) + (size % 2))
		op = create_list_while(RRA, size
				- (find_index_tab(tab, size, *max) + 1));
	else
		op = create_list_while(RA, find_index_tab(tab, size, *max) + 1);
	while (op)
	{
		apply_operation(la, lb, op);
		op = op->next;
	}
	op = NULL;
	free(tab);
}

void	push_swap(t_list *la, t_list *lb, int size)
{
	int		max;
	t_list	*op;

	size = ft_lstsize(la);
	max = -2147483648;
	op = NULL;
	if (ft_lstsize(la) == 1)
		return ;
	while (1)
	{
		if (push_swap_list_sorted(&la, &lb, op))
			break ;
		push_swap_median(&la, &lb, max, &size);
		push_swap_sorting(&max, &la, &lb, size);
		if (push_swap_list_sorted(&la, &lb, op))
			break ;
	}
}
