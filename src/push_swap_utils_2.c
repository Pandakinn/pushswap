/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:55:03 by darian            #+#    #+#             */
/*   Updated: 2022/01/21 16:06:03 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	*generate_median_array(t_list *la, int median, int *size)
{
	int		*arr;
	t_list	*tmp;
	int		i;

	i = 0;
	*size = 0;
	tmp = la;
	while (tmp)
	{
		if (tmp->content > median)
			*size += 1;
		tmp = tmp->next;
	}
	arr = malloc(sizeof(int) * *size);
	while (la)
	{
		if (la->content > median)
			arr[i++] = la->content;
		la = la->next;
	}
	return (arr);
}

int	list_is_sorted_2(int is_end, int i, t_list *la, t_list *lbuff)
{
	t_list	*ltmp;

	if (!is_end)
	{
		ltmp = la;
		while (ltmp && ltmp->next && i < ft_lstsize(la) - 1)
		{
			if (ltmp->next->content < ltmp->content)
				break ;
			i++;
			ltmp = ltmp->next;
		}
		if (ltmp->next == lbuff)
			return (1);
	}
	return (0);
}

void	list_is_sorted_3(t_list **ltmp, int *i, int *is_end)
{
	while ((*ltmp)->next != NULL)
	{
		*i += 1;
		if ((*ltmp)->content > (*ltmp)->next->content)
		{
			*is_end = 1;
			break ;
		}
		*ltmp = (*ltmp)->next;
	}
}

int	list_is_sorted(t_list *la)
{
	t_list	*ltmp;
	t_list	*lbuff;
	int		is_end;
	int		i;

	lbuff = la;
	ltmp = la;
	if (ft_lstsize(la) == 1)
		return (1);
	while (lbuff)
	{
		i = 0;
		is_end = 0;
		ltmp = lbuff;
		list_is_sorted_3(&ltmp, &i, &is_end);
		if (list_is_sorted_2(is_end, i, la, lbuff))
			return (1);
		lbuff = lbuff->next;
	}
	return (0);
}

int	find_max_list(t_list *li)
{
	int	max;

	if (li)
		max = li->content;
	else
		return (0);
	while (li)
	{
		if (li->content > max)
			max = li->content;
		li = li->next;
	}
	return (max);
}
