/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:58:50 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/01 16:03:55 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;

	i = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	while (d_len + i + 1 < dstsize && src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	if (s_len + d_len <= dstsize + s_len)
		return (s_len + d_len);
	return (dstsize + s_len);
}
