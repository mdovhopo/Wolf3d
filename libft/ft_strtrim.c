/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:02:48 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/07 21:55:04 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		st(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

static int				e(const char *s)
{
	unsigned int i;

	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	return (i);
}

char					*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;
	char			*res;

	if (!s)
		return (NULL);
	if ((start = st(s)) == ft_strlen(s))
	{
		res = (char *)malloc(1);
		res[0] = '\0';
		return (res);
	}
	end = e(s);
	i = 0;
	if ((res = (char *)malloc(end - start + 2)))
	{
		while (i + start < end + 1)
		{
			res[i] = s[i + start];
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
