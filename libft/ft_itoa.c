/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:19:43 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/07 21:51:16 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	length(int n)
{
	size_t	len;

	n *= (n >= 0 ? 1 : -1);
	len = 1;
	while (n / 10 > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static	char	*if_min_int_or_0(int n)
{
	char *s;

	if (n == 0)
		s = ft_strdup("0");
	else
		s = ft_strdup("-2147483648");
	return (s);
}

char			*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	int		k;
	int		neg;

	if (n == -2147483648 || n == 0)
		return (if_min_int_or_0(n));
	len = length(n);
	if ((s = (char *)malloc(len + (n >= 0 ? 0 : 1) + 1)))
	{
		k = 10;
		if (n < 0)
			s[0] = '-';
		neg = n > 0 ? 0 : 1;
		len += n > 0 ? 0 : 1;
		n *= n >= 0 ? 1 : -1;
		s[len] = '\0';
		while (len - neg > 0)
		{
			s[len - 1] = n % k + 48;
			n /= 10;
			len--;
		}
	}
	return (s);
}
