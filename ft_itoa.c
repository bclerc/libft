/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 04:23:59 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/20 17:03:45 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_len(size_t value, int base)
{
	int count;

	count = 0;
	while (value >= base)
	{
		value /= base;
		count++;
	}
	return (count + 1);
}

char		*ft_itoa(int value)
{
	static char		hex[] = "0123456789";
	char			*tab;
	unsigned int	absolut;
	int				len;
	int				neg;

	neg = value < 0 ? 2 : 1;
	absolut = ft_abs(value);
	len = get_len(absolut, 10);
	if (!(tab = ft_strnew((len + neg) - 1)))
		return (NULL);
	while (len + neg - 2 >= 0)
	{
		tab[len + neg - 2] = hex[absolut % 10];
		absolut /= 10;
		len--;
	}
	if (neg == 2)
		tab[0] = '-';
	return (tab);
}

char		*ft_itoa_base(long value, int base)
{
	static char		hex[] = "0123456789ABCDEF";
	char			*tab;
	unsigned int	absolut;
	long			len;
	long			neg;

	neg = value < 0 ? 2 : 1;
	absolut = ft_abs(value);
	len = get_len(absolut, base);
	if (!(tab = ft_strnew((len + neg) - 1)))
		return (NULL);
	while (len + neg - 2 >= 0)
	{
		tab[len + neg - 2] = hex[absolut % base];
		absolut /= base;
		len--;
	}
	if (neg == 2)
		tab[0] = '-';
	return (tab);
}
