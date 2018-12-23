/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:20:59 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/10/29 17:56:01 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*r;
	size_t	len;

	c = (unsigned char)c;
	len = ft_strlen(s);
	r = (char *)(s + len - 1);
	if (c == 0)
	{
		r = (char *)(s + len);
		while (r[0] != 0)
			r--;
		return (r);
	}
	while (len--)
	{
		if (r[0] == c)
		{
			return (r);
		}
		r--;
	}
	return (NULL);
}
