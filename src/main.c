/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:09:26 by darian            #+#    #+#             */
/*   Updated: 2022/01/24 18:39:10 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include <stdio.h>

void	ft_lstprintop(t_list *li)
{
	if (!li)
		return ;
	li = li->next;
	if (!li)
		return ;
	while (li != NULL)
		li = li->next;
}

int	*create_array_from_list(t_list *li, int *size)
{
	int	*arr;

	*size = 0;
	arr = malloc(sizeof(int) * ft_lstsize(li));
	while (li != NULL)
	{
		arr[*size] = (int)li->content;
		*size += 1;
		li = li->next;
	}
	return (arr);
}

void	start(t_list *la, int size)
{
	if (is_strictly_sorted(la))
		return ;
	else if (ft_lstsize(la) == 2)
	{
		sa(&la);
		visualise_list(la, NULL);
	}
	else if (ft_lstsize(la) == 3)
		three_number_sort(&la);
	else if (ft_lstsize(la) == 5)
		five_numbers(la, NULL, 0);
	else if (ft_lstsize(la) < 251)
		push_swap_little_list(la, NULL);
	else
		push_swap(la, NULL, size);
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*la;
	int		*arr;
	int		size;

	la = check_error(argv, argc, NULL);
	if (!la)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	arr = create_array_from_list(la, &size);
	start(la, size);
	free(arr);
	ft_lstclear(&la, ft_lstdelcontent);
	return (0);
}
