/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:22:29 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/10/31 19:19:44 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void
	*ft_memccpy(void *dst,
			const void *src, int c, size_t n)
{
	unsigned char			*d;
	unsigned char			*s;
	size_t					i;

	c = (unsigned char)c;
	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
