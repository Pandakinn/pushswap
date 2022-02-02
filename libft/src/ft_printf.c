/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:15:14 by darian            #+#    #+#             */
/*   Updated: 2022/01/10 18:26:21 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && is_type(str[i + 1]))
		{
			if (!call_function(args, str, i, &nb))
				return (0);
			i += 1;
		}
		else
		{
			write(1, &str[i], 1);
			nb++;
		}
		i++;
	}
	return (nb);
}
