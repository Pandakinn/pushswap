/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:08:18 by darian            #+#    #+#             */
/*   Updated: 2022/01/24 18:34:36 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# ifdef VISUALISE
#  undef VISUALISE
#  define VISUALISE 0
# endif

# ifndef VISUALISE
#  define VISUALISE 0
# endif

# include "../libft/libft.h"
# include <stdio.h>

typedef enum s_action
{
	RA = 1,
	RB = 2,
	RR = 3,
	RRA = 4,
	RRB = 5,
	RRR = 6,
	SA = 7,
	SB = 8,
	SS = 9,
	PA = 10,
	PB = 11
}	t_action;

typedef struct s_range
{
	int	start;
	int	end;
}	t_range;

typedef struct s_tab
{
	int	*tab_a;
	int	*tab_b;
	int	size_a;
	int	size_b;
}	t_tab;

void	sa(t_list **li);
void	sb(t_list **li);
void	ss(t_list **la, t_list **lb);

void	pa(t_list **la, t_list **lb);
void	pb(t_list **lb, t_list **la);

void	ra(t_list	**li);
void	rb(t_list	**li);
void	rr(t_list	**la, t_list **lb);
void	rra(t_list	**li);
void	rrb(t_list	**li);
void	rrr(t_list	**la, t_list **lb);

t_list	*check_error(char **args, int size, t_list *la);

void	visualise_list(t_list *la, t_list *lb);
void	ft_lstprintop(t_list *li);

int		find_index_under(int *tab, int size, int nb);
int		find_median(int *array, int n);

int		*generate_median_array(t_list *la, int median, int *size);
int		is_still_under_median(t_list *li, int median, int max);

void	push_swap(t_list *la, t_list *lb, int size);
void	apply_array_operation(t_list **la, t_list **lb, int *max, int last_max);
void	apply_operation(t_list **la, t_list **lb, t_list *op_list);
int		list_is_sorted(t_list *la);
int		*convert_list_to_tab(t_list *li);

t_list	*create_list_while(int op, int n);
t_list	**gen_tab_of_operation(t_tab tab, int *max, int last_max);

t_list	**clear_tab(t_list **arr, int size);
int		find_min_tab(int *arr, int size, int last_max);
int		is_nb_over_and_under(int *arr, int size, int nb_a, int nb_b);
int		find_index_tab(int *arr, int size, int nb);

void	push_swap_little_list(t_list *la, t_list *lb);

int		find_max_list(t_list *li);
int		is_strictly_sorted(t_list *li);

void	three_number_sort(t_list **la);

void	five_numbers(t_list *la, t_list *lb, int i);

int		find_min_list(t_list *li);

int		find_index_op_array(t_list **op_list, t_list *lb);

t_list	*create_list_while_2_rotate_and_pa(int op1, int n1, int op2, int n2);
t_list	*create_list_sa_pa(void);
t_list	*create_list_while(int op, int n);
int		find_index_under(int *tab, int size, int nb);
int		find_index_over(int *tab, int size, int nb);

t_list	**operation_five_numbers_three_la(t_list *la, t_list *lb);

int	find_index_list(t_list *li, int nb);
int	find_index_over_list(t_list *li, int nb);

t_list *operation_five_numbers_four_la(t_list *la, t_list *lb, int max, int min);

#endif