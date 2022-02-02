/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:21:22 by darian            #+#    #+#             */
/*   Updated: 2022/01/21 16:42:04 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//int max = nb max déjà posé depuis la liste a;
//int	last_max = ancien max de la derniere insertion de
// tout les nombre de la liste B a la liste A;
//int	nb = nombre actuelle de la liste B a placer dans la liste A;
//int minimum = nombre le plus petit au dessus de last_max et en dessous de max;
//
//Si c'est le premier tour alors last_max = plus petit de tout les nb - 1;
//
//Si (nb < max && (il y a 0 nb > last_max && 0 nb < max)
//	Alors
//	-> placer nb au dessus de max (soit que max
// 		soit en haut de la liste A et pa le nb a ce moment)
//Sinon Si (nb < minimum)
//	Alors
//	-> placer nb au dessus de minimum (soit que minimum
//		soit en haut de la liste A et pa le nb a ce moment)
//Sinon Si (nb > max)
//	Alors
//	-> placer nb en dessous de max (soit ramener max en
//		bas de liste A et poser nb seul en haut de la liste A)
//Sinon (quand le nombre est entre min et max)
//	int nb_top = 1er nombre > nb
//	int nb_bot = 1er nombre < nb
//	Alors -> placer nb au dessus de nb_bot (soit ramener
//			nb_top en bas de liste A et poser nb seul en haut de la liste A)
//

t_list	*first_number_operation(int i, t_tab tab, int *max)
{
	t_list	*op;

	if (i > (tab.size_b / 2) + (tab.size_b % 2))
	{
		if (find_index_tab(tab.tab_a, tab.size_a, *max)
			> (tab.size_a / 2) + (tab.size_a % 2))
			op = create_list_while_2_rotate_and_pa(RRB, (tab.size_b - i), RRA,
					(tab.size_a - find_index_tab(tab.tab_a, tab.size_a, *max)));
		else
			op = create_list_while_2_rotate_and_pa(RRB, (tab.size_b
						- i), RA, find_index_tab(tab.tab_a, tab.size_a, *max));
	}
	else
	{
		if (find_index_tab(tab.tab_a, tab.size_a, *max)
			> (tab.size_a / 2) + (tab.size_a % 2))
			op = create_list_while_2_rotate_and_pa(RB, i, RRA,
					(tab.size_a - find_index_tab(tab.tab_a, tab.size_a, *max)));
		else
			op = create_list_while_2_rotate_and_pa(RB, i, RA,
					find_index_tab(tab.tab_a, tab.size_a, *max));
	}
	return (op);
}

t_list	*number_under_min_operation(int i, t_tab tab, int min)
{
	t_list	*op;

	if (i > (tab.size_b / 2) + (tab.size_b % 2))
	{
		if (find_index_tab(tab.tab_a, tab.size_a, min) > (tab.size_a / 2)
			+ (tab.size_a % 2))
			op = create_list_while_2_rotate_and_pa(RRB, (tab.size_b - i), RRA,
					(tab.size_a - find_index_tab(tab.tab_a, tab.size_a, min)));
		else
			op = create_list_while_2_rotate_and_pa(RRB, (tab.size_b - i), RA,
					find_index_tab(tab.tab_a, tab.size_a, min));
	}
	else
	{
		if (find_index_tab(tab.tab_a, tab.size_a, min) > (tab.size_a / 2)
			+ (tab.size_a % 2))
			op = create_list_while_2_rotate_and_pa(RB, i, RRA, (tab.size_a
						- find_index_tab(tab.tab_a, tab.size_a, min)));
		else
			op = create_list_while_2_rotate_and_pa(RB, i, RA,
					find_index_tab(tab.tab_a, tab.size_a, min));
	}
	return (op);
}

t_list	*number_over_max_operation(int i, t_tab tab, int *max)
{
	t_list	*op;

	if (i > (tab.size_b / 2) + (tab.size_b % 2))
	{
		if (find_index_tab(tab.tab_a, tab.size_a, *max) + 1 > (tab.size_a / 2)
			+ (tab.size_a % 2))
			op = create_list_while_2_rotate_and_pa(RRB, (tab.size_b - i), RRA,
					(tab.size_a - (find_index_tab(tab.tab_a, tab.size_a, *max)
							+ 1)));
		else
			op = create_list_while_2_rotate_and_pa(RRB, (tab.size_b - i),
					RA, find_index_tab(tab.tab_a, tab.size_a, *max) + 1);
	}
	else
	{
		if (find_index_tab(tab.tab_a, tab.size_a, *max) + 1 > (tab.size_a / 2)
			+ (tab.size_a % 2))
			op = create_list_while_2_rotate_and_pa(RB, i, RRA, (tab.size_a
						- (find_index_tab(tab.tab_a, tab.size_a, *max) + 1)));
		else
			op = create_list_while_2_rotate_and_pa(RB, i, RA,
					find_index_tab(tab.tab_a, tab.size_a, *max) + 1);
	}
	return (op);
}

t_list	*number_between_min_max(int nb, t_tab tab, int i)
{
	int		under;
	t_list	*op;

	under = find_index_under(tab.tab_a, tab.size_a, nb);
	if (i > (tab.size_b / 2) + (tab.size_b % 2))
	{
		if (under + 1 > (tab.size_a / 2) + (tab.size_a % 2))
			op = create_list_while_2_rotate_and_pa(RRB,
					(tab.size_b - i), RRA, (tab.size_a - (under + 1)));
		else
			op = create_list_while_2_rotate_and_pa(RRB,
					(tab.size_b - i), RA, under + 1);
	}
	else
	{
		if (under + 1 > (tab.size_a / 2) + (tab.size_a % 2))
			op = create_list_while_2_rotate_and_pa(RB, i, RRA,
					(tab.size_a - (under + 1)));
		else
			op = create_list_while_2_rotate_and_pa(RB, i, RA, under + 1);
	}
	return (op);
}

t_list	**gen_tab_of_operation(t_tab tab, int *max, int last_max)
{
	t_list	**arr;
	int		min;
	int		nb;
	int		i;

	i = 0;
	min = find_min_tab(tab.tab_a, tab.size_a, last_max);
	arr = malloc(sizeof(t_list *) * tab.size_b);
	while (i < tab.size_b)
	{
		nb = tab.tab_b[i];
		if (nb < *max && !is_nb_over_and_under(tab.tab_a,
				tab.size_a, last_max, *max))
			arr[i] = first_number_operation(i, tab, max);
		else if (nb < min)
			arr[i] = number_under_min_operation(i, tab, min);
		else if (nb > *max)
			arr[i] = number_over_max_operation(i, tab, max);
		else
			arr[i] = number_between_min_max(nb, tab, i);
		i++;
	}
	return (arr);
}
