/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:08:28 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/09 17:08:29 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** transforms value s from range a.x - a.y to value
** (witch returns) to range b.x - b.y
*/

double	ft_map(double s, t_vec2 a, t_vec2 b)
{
	return (b.x + (s - a.x) * (b.y - b.x) / (a.y - a.x));
}
