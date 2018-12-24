/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:44:03 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/07 21:15:18 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	s = (long long *)s;
	i = n / sizeof(long long);
	while (i-- > 0)
	{
		s = 0;
		s++;
	}
	s = (char *)s;
	i = n % sizeof(long long);
	while (i-- > 0)
	{
		s = 0;
		s++;
	}
}
