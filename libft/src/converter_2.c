/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:56:56 by dasereno          #+#    #+#             */
/*   Updated: 2021/12/14 18:26:26 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	size_nb_base(unsigned int nb, unsigned int base_len)
{
	int	n;

	n = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= base_len;
		n++;
	}
	return (n);
}

unsigned int	val(char c, int lower)
{
	if (c >= '0' && c <= '9')
		return ((unsigned int)c - '0');
	else if (c < '0' && c > '9' && lower)
		return ((unsigned int)c - 'a' + 10);
	else
		return ((unsigned int)c - 'A' + 10);
}

int	str_islower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			return (0);
		i++;
	}
	return (1);
}
