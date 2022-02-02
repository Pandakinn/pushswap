/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:59:07 by darian            #+#    #+#             */
/*   Updated: 2022/01/21 18:48:30 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	array_sort(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				ft_swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

int	find_median(int *arr, int n)
{
	float	median;
	int		x;

	median = 0;
	array_sort(arr, n);
	if (n % 2 == 0)
		median = (arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
	else
		median = arr[n / 2];
	x = (int)median;
	if (median - x != 0)
		return (x + 1);
	return (x);
}
