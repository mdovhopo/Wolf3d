/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:24:50 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/07 21:04:51 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if ((s1 == NULL && s2) || (s1 && s2 == NULL))
		return (0);
	else if (s1 == NULL && s2 == NULL)
		return (1);
	return (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
}
