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
	size_t		i;
	long long	*str1;
	char		*str2;

	str1 = (long long *)s;
	i = 0;
	while (i < n / sizeof(long long))
		str1[i++] = 0;
	str2 = (char *)(s + i * sizeof(long long));
	i = 0;
	while (i < n % sizeof(long long))
		str2[i++] = 0;
}
