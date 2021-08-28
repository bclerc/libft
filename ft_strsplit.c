/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 23:44:48 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/28 18:16:09 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	short	is_a_word(char before, char current, char strip)
{
	return ((before == strip || before == 0) && current != strip);
}

static	int	total_words(char const *s, char strip)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (s[i])
	{
		if (is_a_word(s[i - 1], s[i], strip))
			total++;
		i++;
	}
	return (total);
}

static	int	word_len(const char *c, char strip)
{
	unsigned int	i;

	i = 0;
	while (c[i] && c[i] != strip)
		i++;
	return (i);
}

int	check_fuck_norm(int i, char *tmp, char c)
{
	if (i > 0)
		return (is_a_word(tmp[i - 1], tmp[i], c));
	return (is_a_word(c, tmp[i], c));
}

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	char	*tmp;
	int		i;
	int		stri;

	str = (char **)malloc((total_words(s, c) + 1) * sizeof(char *));
	if (!s || !(str))
		return (NULL);
	tmp = (char *)s;
	i = -1;
	stri = -1;
	while (tmp[++i] && stri++)
	{
		if (check_fuck_norm(i, tmp, c))
		{
			str[stri] = ft_strndup(&tmp[i], word_len(&tmp[i], c));
			if (!str[stri])
			{
				free(str);
				return (NULL);
			}
		}
	}
	str[stri] = 0;
	return (str);
}
