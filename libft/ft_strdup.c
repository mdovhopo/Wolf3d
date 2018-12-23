/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 18:23:30 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/03 17:17:26 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		length;

	length = 0;
	while (src[length] != '\0')
		length++;
	str = (char *)malloc(sizeof(char) * length + 1);
	if (str == NULL)
		return (NULL);
	length = 0;
	while (src[length] != '\0')
	{
		str[length] = src[length];
		length++;
	}
	str[length] = '\0';
	return (str);
}
