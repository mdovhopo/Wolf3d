/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 14:12:57 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/10/29 19:30:25 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*s1;

	i = 0;
	d1 = (unsigned char *)dst;
	s1 = (unsigned char *)src;
	while (i < n)
	{
		d1[i] = s1[i];
		i++;
	}
	return (dst);
}
