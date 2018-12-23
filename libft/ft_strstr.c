/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:31:56 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/10/29 19:39:24 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*hstack;
	int		i;
	int		j;

	hstack = (char *)haystack;
	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return (hstack);
	while (haystack[i])
	{
		j = 0;
		while (needle[j])
		{
			if (haystack[i + j] != needle[j])
				break ;
			j++;
			if (needle[j] == '\0')
				return (&hstack[i]);
		}
		i++;
	}
	return (NULL);
}
