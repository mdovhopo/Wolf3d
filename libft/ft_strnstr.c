/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:10:30 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/10/29 19:39:22 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hstack;
	size_t	i;
	size_t	j;

	hstack = (char *)haystack;
	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return (hstack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && i + j < len)
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
