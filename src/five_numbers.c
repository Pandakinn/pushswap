/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:09:19 by darian            #+#    #+#             */
/*   Updated: 2022/01/24 18:47:29 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	sorted(t_list **la, t_list **lb)
{
	int		max;
	int		*tab;
	t_list	*op;
	int		size;

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

void	operations(t_list **la, t_list **lb, int i)
{
	int		max;
	t_list	**op_list;
	t_list	*op;
	t_list	*tmp;
	int		size;

	op_list = operation_five_numbers_three_la(*la, *lb);
	i = find_index_op_array(op_list, *lb);
	op_list[i] = op_list[i]->next;
	size = ft_lstsize(*lb);
	while (op_list[i])
	{
		apply_operation(la, lb, op_list[i]);
		op_list[i] = op_list[i]->next;
	}
	max = find_max_list(*la);
	op = operation_five_numbers_four_la(*la, *lb, max, find_min_list(*la));
	tmp = op;
	op = op->next;
	while (op)
	{
		apply_operation(la, lb, op);
		op = op->next;
	}
	// ft_lstclear(&tmp, ft_lstdelcontent);
	i = 0;
	while (i < size - 1)
	{
		// if (op_list[i] != NULL)
			ft_lstclear(&op_list[i], ft_lstdelcontent);
		i++;
	}
}

void	five_numbers(t_list *la, t_list *lb, int i)
{
	pb(&lb, &la);
	visualise_list(la, lb);
	pb(&lb, &la);
	visualise_list(la, lb);
	if (!is_strictly_sorted(la))
		three_number_sort(&la);
	operations(&la, &lb, i);
	sorted(&la, &lb);
}
