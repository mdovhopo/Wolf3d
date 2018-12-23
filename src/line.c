/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:27:42 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/23 18:27:55 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** error.x - delta error
** error.y - error
*/

void	line(t_intvec2 start, t_intvec2 end, t_win *win)
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
			((int *)win->img)[start.y * WIDTH + start.x] = win->color;
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
