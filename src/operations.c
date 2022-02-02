/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:57:54 by darian            #+#    #+#             */
/*   Updated: 2022/01/21 16:47:53 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_list	*double_r(t_range op, t_range n, int *i, int *nb)
{
	t_list	*li;

	li = NULL;
	if ((op.start == RRA || op.start == RRB)
		&& (op.end == RRA || op.end == RRB))
	{
		while (*i < n.start && *i < n.end)
		{
			ft_lstadd_back(&li, ft_lstnew(RRR));
			*i += 1;
			*nb += 1;
		}
	}
	else if ((op.start == RA || op.start == RB)
		&& (op.end == RA || op.end == RB))
	{
		while (*i < n.start && *i < n.end)
		{
			ft_lstadd_back(&li, ft_lstnew(RR));
			*i += 1;
			*nb += 1;
		}
	}
	return (li);
}

t_list	*create_list_while_2_rotate_and_pa(int op1, int n1, int op2, int n2)
{
	int		j;
	int		i;
	t_list	*li;
	int		nb;

	li = NULL;
	i = 0;
	nb = 0;
	if (n1 > 0 && n2 > 0)
		li = double_r((t_range){op1, op2}, (t_range){n1, n2}, &i, &nb);
	j = i;
	while (j++ < n1)
	{
		ft_lstadd_back(&li, ft_lstnew(op1));
		nb++;
	}
	j = i;
	while (j++ < n2)
	{
		ft_lstadd_back(&li, ft_lstnew(op2));
		nb++;
	}
	ft_lstadd_back(&li, ft_lstnew(PA));
	ft_lstadd_front(&li, ft_lstnew(nb + 1));
	return (li);
}

t_list	*create_list_sa_pa(void)
{
	t_list	*op;

	op = NULL;
	ft_lstadd_back(&op, ft_lstnew(2));
	ft_lstadd_back(&op, ft_lstnew(SA));
	ft_lstadd_back(&op, ft_lstnew(PA));
	return (op);
}

t_list	*create_list_while(int op, int n)
{
	int		i;
	t_list	*li;

	li = NULL;
	i = 0;
	while (i < n)
	{
		ft_lstadd_back(&li, ft_lstnew(op));
		i++;
	}
	return (li);
}

int	find_index_under(int *tab, int size, int nb)
{
	int	val;
	int	i;
	int	index;

	index = 0;
	i = 0;
	val = -2147483648;
	while (i < size)
	{
		if (tab[i] > val && tab[i] < nb)
		{
			val = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}
