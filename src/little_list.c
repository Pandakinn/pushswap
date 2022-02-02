/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:06:31 by darian            #+#    #+#             */
/*   Updated: 2022/01/21 18:48:25 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	push_swap_lil_push_all(t_list **la, t_list **lb, int min, int max)
{
	while (ft_lstsize(*la) != 2)
	{
		if ((*la)->content != max && (*la)->content != min)
			pb(lb, la);
		else
			ra(la);
		visualise_list(*la, *lb);
	}
}

void	push_swap_lil_sort(t_list **la, t_list **lb)
{
	int		max;
	int		*tab;
	int		size;
	t_list	*op;

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
	}
}

void	push_swap_little_list(t_list *la, t_list *lb)
{
	int		min;
	int		max;

	max = find_max_list(la);
	min = find_min_list(la);
	push_swap_lil_push_all(&la, &lb, min, max);
	while (lb)
		apply_array_operation(&la, &lb, &max, -2147483648);
	push_swap_lil_sort(&la, &lb);
}
