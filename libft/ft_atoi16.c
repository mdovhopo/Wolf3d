/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:39:08 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/04 18:39:11 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int			is_a_f(char c)
{
	return ((c > 64 && c < 71) || (c > 96 && c < 103));
}

static int			length(char *s)
{
	int len;

	len = 0;
	while ((ft_isdigit(s[len]) || is_a_f(s[len])) && s[len])
		len++;
	return (len);
}

static int			is_white_space(char *s)
{
	if (*s == ' ' || *s == '\t' || *s == '\v' ||
			*s == '\n' || *s == '\r' || *s == '\f')
		return (1);
	else
		return (0);
}

static int			is_upper(char c)
{
	if (c < 90)
		return (55);
	return (87);
}

int					ft_atoi16(const char *str)
{
	int				res;
	int				len;
	int				base;
	char			*s;
	int				tmp;

	res = 0;
	base = 1;
	s = (char *)str;
	s += 2;
	while ((is_white_space(s)) && *s != '\0')
		s++;
	len = length(s);
	while (len > 0 && (ft_isdigit(s[len - 1]) || is_a_f(s[len - 1])))
	{
		if (is_a_f(s[len - 1]))
			tmp = s[len - 1] - is_upper(s[len - 1]);
		else
			tmp = s[len - 1] - '0';
		res += tmp * base;
		base *= 16;
		len--;
	}
	return (res);
}
