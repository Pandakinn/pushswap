/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstisin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:04:35 by darian            #+#    #+#             */
/*   Updated: 2022/01/05 18:26:33 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstisin(t_list *li, int nb)
{
	int	i;

	i = 0;
	while (li != NULL)
	{
		if (li->content == nb) 
			return (i + 1);
		li = li->next;
		i++;
	}
	return (0);
}