/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:52:00 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/24 14:52:01 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			motion_mouse(int x, int y, void *param)
{
	t_win *win;

	win = (t_win *)param;
	if (win->mousePosX - x != 0)
	{
		double rotAngle = win->mousePosX - x > 0 ? -0.1: 0.1;
		double oldDirX = win->dirX;
		win->dirX = win->dirX * cos(-rotAngle) - win->dirY * sin(-rotAngle);
		win->dirY = oldDirX * sin(-rotAngle) + win->dirY * cos(-rotAngle);
		double oldPlaneX = win->planeX;
		win->planeX = win->planeX * cos(-rotAngle) - win->planeY * sin(-rotAngle);
		win->planeY = oldPlaneX * sin(-rotAngle) + win->planeY * cos(-rotAngle);
		win->mousePosX = x;
		render(win);
	}
	return (0);	
}
