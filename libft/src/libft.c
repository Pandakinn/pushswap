/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:54:15 by darian            #+#    #+#             */
/*   Updated: 2021/12/14 18:26:01 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	len_llu(unsigned long long nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_llu(unsigned long long nb)
{
	char				*str;
	unsigned long long	n;
	int					i;

	n = nb;
	i = len_llu(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

// int	nb_len(unsigned int nb)
// {
// 	int	n;

// 	n = 0;
// 	if (nb == 0)
// 		return (1);
// 	while (nb > 0)
// 	{
// 		nb /= 10;
// 		n++;
// 	}
// 	return (n);
// }

// char	*ft_itoa(unsigned int nb)
// {
// 	int		i;
// 	char	*str;

// 	str = malloc(sizeof(char) * (nb_len(nb) + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	if (nb == 0)
// 	{
// 		str[0] = '0';
// 		str[1] = 0;
// 		return (str);
// 	}
// 	while (nb > 0)
// 	{
// 		str[i++] = (nb % 10) + '0';
// 		nb /= 10;
// 	}
// 	str[i] = 0;
// 	return (str_rev(str));
// }
