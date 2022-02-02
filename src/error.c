/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:45:38 by darian            #+#    #+#             */
/*   Updated: 2022/01/21 19:02:16 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	get_string_args_body(char	*str, int *i, int *j, int *nb)
{
	while (str[*i + *j] >= '0' && str[*i + *j] <= '9')
		*j += 1;
	if (str[*i + *j] != ' ' && str[*i + *j] != 0)
		return (0);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*nb = (*nb * 10) + str[*i] - '0';
		*i += 1;
	}
	return (1);
}

void	get_strings_args_neg(char *str, int *i, int *neg)
{
	if (str[*i] == '-')
	{
		*neg *= -1;
		*i += 1;
	}
}

t_list	*get_string_args(char *str, int argc, int i, int j)
{
	int		nb;
	t_list	*la;
	int		neg;

	la = NULL;
	neg = 1;
	nb = 0;
	if (argc != 2)
		return (NULL);
	while (str[i])
	{
		j = 0;
		get_strings_args_neg(str, &i, &neg);
		if (!get_string_args_body(str, &i, &j, &nb))
			return (NULL);
		if (ft_lstisin(la, nb * neg))
			return (NULL);
		ft_lstadd_back(&la, ft_lstnew(nb * neg));
		neg = 1;
		nb = 0;
		if (!str[i++])
			break ;
	}
	return (la);
}

void	*check_error_start(char **args, int i, t_list **la)
{
	int	j;

	j = 0;
	while (args[i][j])
	{
		if (!ft_isdigit(args[i][j]))
		{
			if (!(args[i][j] == '-' && j == 0))
			{
				ft_lstclear(la, ft_lstdelcontent);
				return (NULL);
			}
		}
		j++;
	}
	return ((void *)1);
}

t_list	*check_error(char **args, int size, t_list *la)
{
	int	i;

	i = 1;
	if (size < 2)
		return (NULL);
	la = get_string_args(args[1], size, 0, 0);
	if (la)
		return (la);
	while (i < size)
	{
		if (check_error_start(args, i, &la) == NULL)
			return (NULL);
		if (ft_lstisin(la, ft_atoi(args[i])))
			return (NULL);
		ft_lstadd_back(&la, ft_lstnew(ft_atoi(args[i])));
		i++;
	}
	return (la);
}
