/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:40:11 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/07 20:47:45 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_char(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0' && s[count] != c)
		count++;
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	k;

	if ((split = malloc(sizeof(char *) * ft_count_words(s, c) + 1)))
	{
		k = 0;
		i = 0;
		while (i < ft_count_words(s, c))
		{
			j = 0;
			while (s[k] == c)
				k++;
			if ((split[i] = malloc(sizeof(char) * count_char(&s[k], c) + 1)))
			{
				while (s[k] != c && s[k] != '\0')
					split[i][j++] = s[k++];
				split[i++][j] = '\0';
			}
		}
		split[i] = NULL;
	}
	return (split);
}
