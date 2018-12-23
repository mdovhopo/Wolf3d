/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:45:20 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/03 17:17:14 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*str1;
	char	*str2;
	int		i;
	int		c_join;

	if (!s1 || !s2)
		return (NULL);
	str1 = (char *)s1;
	str2 = (char *)s2;
	join = (char *)malloc(sizeof(char) * ft_strlen(str1) + ft_strlen(str2) + 1);
	if (join)
	{
		c_join = 0;
		i = 0;
		while (s1[i] != '\0')
			join[c_join++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			join[c_join++] = s2[i++];
		join[c_join] = '\0';
	}
	return (join);
}
