/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:01:17 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/10/28 12:59:29 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	s1_length;
	size_t	s2_length;
	int		i;

	i = 0;
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	while (s2_length--)
		s1[s1_length++] = s2[i++];
	s1[s1_length] = '\0';
	return (s1);
}
