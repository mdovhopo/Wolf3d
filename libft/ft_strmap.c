/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:34:13 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/07 20:45:25 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*s1;
	size_t	len;

	i = 0;
	if (!s && !f)
		return (NULL);
	len = ft_strlen(s);
	s1 = (char *)malloc(len + 1);
	if (s1)
	{
		while (s[i])
		{
			s1[i] = f(s[i]);
			i++;
		}
		s1[i] = '\0';
	}
	return (s1);
}
