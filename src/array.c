/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:19:48 by darian            #+#    #+#             */
/*   Updated: 2022/01/21 18:48:44 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_list	**clear_tab(t_list **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_lstclear(&arr[i], ft_lstdelcontent);
		arr[i] = NULL;
		i++;
	}
	return (arr);
}

int	find_min_tab(int *arr, int size, int last_max)
{
	int	min;
	int	i;

	i = 0;
	min = arr[i];
	while (i < size)
	{
		if (arr[i] < min && arr[i] > last_max)
			min = arr[i];
		i++;
	}
	return (min);
}

int	is_nb_over_and_under(int *arr, int size, int nb_a, int nb_b)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] > nb_a && arr[i] < nb_b)
			return (1);
		i++;
	}
	return (0);
}

int	find_index_tab(int *arr, int size, int nb)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == nb)
			return (i);
		i++;
	}
	return (0);
}
