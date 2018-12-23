/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:12:35 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/07 20:45:31 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned char	i;
	char			*s1;

	i = 0;
	if (!s && !f)
		return (NULL);
	s1 = (char *)malloc(ft_strlen(s) + 1);
	if (s1)
	{
		while (s[i])
		{
			s1[i] = f(i, s[i]);
			i++;
		}
		s1[i] = '\0';
	}
	return (s1);
}
