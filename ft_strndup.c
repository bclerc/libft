/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:09:33 by bclerc            #+#    #+#             */
/*   Updated: 2021/01/19 15:38:23 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *str, int len)
{
	int		i;
	char	*tmp;

	if (!(tmp = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_bzero(tmp, len);
	i = 0;
	while (i < len)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
