/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:29:51 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/10/28 12:58:45 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	s1_length;
	size_t	s2_length;
	size_t	i;

	i = 0;
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	while (i < n && s2_length--)
		s1[s1_length++] = s2[i++];
	s1[s1_length] = '\0';
	return (s1);
}
