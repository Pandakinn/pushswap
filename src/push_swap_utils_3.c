/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:48:14 by darian            #+#    #+#             */
/*   Updated: 2022/01/24 18:31:49 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	find_index_over(int *tab, int size, int nb)
{
	int	val;
	int	i;
	int	index;

	index = 0;
	i = 0;
	val = 2147483647;
	while (i < size)
	{
		if (tab[i] < val && tab[i] > nb)
		{
			val = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	find_index_list(t_list *li, int nb)
{
	int	i;

	i = 0;
	while (li)
	{
		if (li->content == nb)
			return (i);
		i++;
		li = li->next;
	}
	return (0);
}

int	find_index_over_list(t_list *li, int nb)
{
	int	val;
	int	i;
	int	index;

	index = 0;
	i = 0;
	if (li)
		val = li->content;
	val = __INT_MAX__;
	while (li)
	{
		if (li->content < val && li->content > nb)
		{
			val = li->content;
			index = i;
		}
		i++;
		li = li->next;
	}
	return (index);
}
