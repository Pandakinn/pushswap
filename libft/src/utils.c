/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:54:43 by darian            #+#    #+#             */
/*   Updated: 2021/12/14 18:26:09 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	size_nb(int nbr)
{
	int			n;
	long int	nb;

	nb = (long int)nbr;
	n = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		n++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		n++;
	}
	return (n);
}

int	size_nb_unsigned(unsigned int nbr)
{
	int			n;
	long int	nb;

	nb = (long int)nbr;
	n = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		n++;
	}
	return (n);
}
