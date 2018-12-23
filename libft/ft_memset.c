/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 12:28:09 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/07 21:58:29 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*s;
	unsigned char	c1;

	c1 = (unsigned char)c;
	s = (char *)b;
	i = 0;
	while (i < len)
	{
		s[i] = c1;
		i++;
	}
	return (b);
}
