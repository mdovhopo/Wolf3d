/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:06:53 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/10/29 17:56:04 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*r;
	size_t	len;

	c = (unsigned char)c;
	r = (char *)s;
	len = ft_strlen(s);
	if (c == 0)
	{
		while (r[0] != 0)
			r++;
		return (r);
	}
	while (len-- > 0)
	{
		if (r[0] == c)
			return (r);
		r++;
	}
	return (NULL);
}
