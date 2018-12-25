/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:20:10 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/25 16:20:31 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	line(t_intvec2 start, t_intvec2 end, t_frame *f, char *pixels)
{
	t_intvec2	delta;
	t_intvec2	sign;
	t_intvec2	error;

	delta = ft_new_intvec2(abs(end.x - start.x), -abs(end.y - start.y));
	sign = ft_new_intvec2(start.x < end.x ? 1 : -1, start.y < end.y ? 1 : -1);
	error = ft_new_intvec2(delta.x + delta.y, 2 * (delta.x + delta.y));
	while (start.x != end.x || start.y != end.y)
	{
		if (start.x > 0 && start.x < WIDTH && start.y > 0 && start.y < HEIGHT)
			((int *)pixels)[start.y * WIDTH + start.x] = f->color;
		error.y = error.x * 2;
		if (error.y >= delta.y)
		{
			error.x += delta.y;
			start.x += sign.x;
		}
		if (error.y <= delta.x)
		{
			error.x += delta.x;
			start.y += sign.y;
		}
	}
}
