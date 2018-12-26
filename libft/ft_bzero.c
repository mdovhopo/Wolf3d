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
/*
void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	long long	*s1;
	unsigned char		*s2;

	i = 0;
	s2 = (char *)s;
	while (s2[i])
		s2[i++] = 0;
	i = n / sizeof(long long);
	while (0 && i-- > 0)
	{
		*s1 = 0;
		s1++;
	}
	s2 = (char *)s1;
	i = n % sizeof(long long);
	while (0 && i-- > 0)
	{
		*s2 = 0;
		s2++;
	}
}
*/
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}