/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:38:07 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/28 17:38:09 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *s, char c)
{
	int		count;
	int		i;
	int		is_word;

	if (!s)
		return (-2);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			is_word = 1;
		while (s[i] != c && s[i] != '\0')
		{
			if (is_word == 1)
			{
				count++;
				is_word = 0;
			}
			i++;
		}
	}
	return (count);
}
