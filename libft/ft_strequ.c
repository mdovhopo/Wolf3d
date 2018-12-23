/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:17:23 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/07 20:51:28 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if ((s1 == NULL && s2) || (s1 && s2 == NULL))
		return (0);
	else if (s1 == NULL && s2 == NULL)
		return (1);
	while (*s1 == *s2)
	{
		if (!*s1 && !*s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}
