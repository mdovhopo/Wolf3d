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

	i = 0;
	dst = (unsigned char *)dst;
	src = (unsigned char *)src;
	while (0 && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
