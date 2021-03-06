/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:40:12 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/02 14:40:27 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_show_binary(unsigned int x)
{
	int i;

	i = (sizeof(int) * 8) - 1;
	while (i >= 0)
	{
		(x & (1u << i)) ? write(1, "1", 1) : write(1, "0", 1);
		i--;
	}
	write(1, "\n", 1);
}
