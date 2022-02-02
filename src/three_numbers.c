/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:54:08 by darian            #+#    #+#             */
/*   Updated: 2022/01/24 18:42:00 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

/*
	top
	mid
	bot

	si top > mid && mid < bot && bot > top
		sa
	si top > mid && mid > bot && bot < top
		sa
		rra
	si top > mid && mid < bot && bot < top
		ra
	si top < mid && mid > bot && bot > top
		sa
		ra
	si	top < mid && mid > bot && bot < top
		rra

	top > mid && mid < bot && bot > top
*/

void	three_number_sort_2(int top, int mid, int bot, t_list **la)
{
	if (top > mid && mid < bot && bot > top)
		sa(la);
	else if (top > mid && mid > bot && bot < top)
	{
		sa(la);
		visualise_list(*la, NULL);
		rra(la);
	}
	else if (top > mid && mid < bot && bot < top)
		ra(la);
	else if (top < mid && mid > bot && bot > top)
	{
		sa(la);
		visualise_list(*la, NULL);
		ra(la);
	}
	else
		rra(la);
}

void	three_number_sort(t_list **la)
{
	int	top;
	int	mid;
	int	bot;

	top = (*la)->content;
	mid = (*la)->next->content;
	bot = (*la)->next->next->content;
	three_number_sort_2(top, mid, bot, la);
	visualise_list(*la, NULL);
}
