/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:54:30 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/03 12:29:56 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			length(char *s)
{
	int len;

	len = 0;
	while (s[len] >= '0' && s[len] <= '9' && s[len])
		len++;
	return (len);
}

static char			*is_plus_minus(char *s, int *ten)
{
	if (*s == '-')
	{
		s++;
		*ten = -1;
	}
	else if (*s == '+')
	{
		s++;
		*ten = 1;
	}
	else
		*ten = 1;
	return (s);
}

static int			is_white_space(char *s)
{
	if (*s == ' ' || *s == '\t' || *s == '\v' ||
			*s == '\n' || *s == '\r' || *s == '\f')
		return (1);
	else
		return (0);
}

int					ft_atoi(const char *str)
{
	long long		res;
	int				len;
	int				ten;
	char			*s;

	res = 0;
	s = (char *)str;
	while ((is_white_space(s)) && *s != '\0')
		s++;
	s = is_plus_minus(s, &ten);
	len = length(s);
	while (len > 0 && s[len - 1] >= '0' && s[len - 1] <= '9')
	{
		res += (s[len - 1] - '0') * ten;
		ten *= 10;
		len--;
	}
	return ((int)res);
}
