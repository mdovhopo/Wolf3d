/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:24:31 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/10/29 20:18:15 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = (char *)malloc(size + 1);
	if (mem)
	{
		while (i < size + 1)
		{
			mem[i] = '\0';
			i++;
		}
	}
	return (mem);
}
