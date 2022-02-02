/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:03:41 by dasereno          #+#    #+#             */
/*   Updated: 2022/01/05 18:28:08 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int *))
{
	if (lst != NULL)
	{
		while (lst != NULL)
		{
			(*f)(&lst->content);
			lst = lst->next;
		}
	}
}
