/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:47:50 by darian            #+#    #+#             */
/*   Updated: 2022/01/21 18:48:20 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	is_in_list(t_list *li, int nb)
{
	while (li)
	{
		if (li->content == nb)
			return (1);
		li = li->next;
	}
	return (0);
}

int	find_min_list(t_list *li)
{
	int	min;

	if (li)
		min = li->content;
	else
		return (0);
	while (li)
	{
		if (li->content < min)
			min = li->content;
		li = li->next;
	}
	return (min);
}

int	is_strictly_sorted(t_list *li)
{
	while (li->next)
	{
		if (li->content > li->next->content)
			return (0);
		li = li->next;
	}
	return (1);
}
