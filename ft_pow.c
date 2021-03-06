/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:42:10 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/20 17:04:05 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int nb, int pow)
{
	int i;

	while (pow > 0)
	{
		i = nb * i;
		pow--;
	}
	return (nb);
}
